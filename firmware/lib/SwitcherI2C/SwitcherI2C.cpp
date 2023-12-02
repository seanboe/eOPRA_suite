#include "SwitcherI2C.h"

SwitcherI2C::SwitcherI2C() {};

#define SWITCHER_WIRE   Wire

bool SwitcherI2C::init(uint8_t addr, uint8_t intPin, SwitcherGlobalCommData * commData) {

  // Uses port 0
  SWITCHER_WIRE.begin(addr);

  this->commData = commData;

  this->intPin = intPin;
  this->commandQueue = STOP;
  this->dataQueued = false;

  this->prevRandCheck = 0xFF;

  return true;
};

TwoWire SwitcherI2C::getWireInstance() {
  return SWITCHER_WIRE;
}

// // Packet structure is START | RANDINT | DATA | STOP
// // Keep in mind that the maximum buffer size is defined by MAX_BUFFER
// bool SwitcherI2C::write(uint8_t * data, uint8_t dataSize) {
//   uint8_t buffSize = dataSize + 3;

//   if (buffSize > MAX_BUFFER)
//     return false;

//   uint8_t buffer[buffSize];

//   this->prevRandCheck = this->encode(buffer, buffSize, data);

//   SWITCHER_WIRE.beginTransmission(this->peripheralAddress);
//   SWITCHER_WIRE.write(buffer, buffSize);
//   SWITCHER_WIRE.endTransmission();

//   return true;
// };

void SwitcherI2C::receive(uint8_t bytes) {
  uint8_t buffer[MAX_BUFFER];
  SWITCHER_WIRE.readBytes(buffer, bytes);

  uint8_t data[bytes - 3];

  this->prevRandCheck = this->decode(buffer, bytes, data);

  this->commandQueue = data[0];
  this->dataQueued = true;
}

void SwitcherI2C::answerRequest() {
  if (!this->dataQueued)
    return;

  uint8_t data[] = {STOP};

  switch (this->commandQueue) {
    case GET_STIMULATION_PORT: data[0] = this->commData->port; break;
  }
  
  // uint8_t dataSize = sizeof(data) / sizeof(uint8_t);
  uint8_t dataSize = 1;

  uint8_t encoded[dataSize + 3];

  this->encode(data, dataSize, encoded, this->prevRandCheck);

  SWITCHER_WIRE.write(encoded, dataSize + 3);
}

void SwitcherI2C::interruptSwitcher() {
  digitalWrite(this->intPin, HIGH);
  delay(1);
  digitalWrite(this->intPin, LOW);
}

uint8_t SwitcherI2C::decode(uint8_t * buffer, uint8_t buffSize, uint8_t * decoded) {

  if ((uint8_t)buffer[0] != START) {
    return 0xFF;
  }

  // uint8_t dataQueue[buffSize - 3]; // 3 Accounts for the start, check, and stop 
  memset(decoded, 0, buffSize - 3);

  for (int x = 0; x < buffSize - 3; x++) {
    if ((uint8_t)buffer[x + 2] == STOP) {
      break;
    }
    decoded[x] = (uint8_t)buffer[x + 2];
  }

  return buffer[1];
};

uint8_t SwitcherI2C::encode(uint8_t * data, uint8_t dataSize, uint8_t * encoded, uint8_t randInt) {

  if (dataSize + 3 > MAX_BUFFER)
    return 0xFF;

  memset(encoded, 0, dataSize + 3);

  memcpy(encoded + 2, data, dataSize);
  encoded[0] = START;

  if (randInt == 0xFF)
    encoded[1] = (uint8_t)random(0, 127);
  else
    encoded[1] = randInt;

  encoded[dataSize + 2] = STOP;

  return encoded[1];
};