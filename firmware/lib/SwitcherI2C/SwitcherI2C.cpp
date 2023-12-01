#include "SwitcherI2C.h"

SwitcherI2C::SwitcherI2C() {};

#define SWITCHER_WIRE   Wire

bool SwitcherI2C::init(uint8_t addr, uint8_t intPin, SwitcherGlobalCommData * commData, MainGlobalCommData) {
  CommHandler::init();

  // Uses port 0
  SWITCHER_WIRE.begin(addr);

  this->commData = commData;

  this->intPin = intPin;
  this->commandQueue = STOP;
  this->dataQueued = false;

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

bool SwitcherI2C::receive(uint8_t bytes) {
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
  
  uint8_t dataSize = sizeof(data) / sizeof(uint8_t);

  uint8_t encoded[dataSize + 3];

  this->encode(data, dataSize, encoded, this->prevRandCheck);

  SWITCHER_WIRE.write(encoded, dataSize + 3);
}

void SwitcherI2C::interruptSwitcher() {
  digitalWrite(this->intPin, HIGH);
  delay(1);
  digitalWrite(this->intPin, LOW);
}