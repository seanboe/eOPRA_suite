#include "SwitcherI2C.h"

SwitcherI2C::SwitcherI2C() {};

#define SWITCHER_WIRE   Wire1

bool SwitcherI2C::init(uint8_t peripheralAddress) {

  this->peripheralAddress = peripheralAddress;

  // Uses port 0
  SWITCHER_WIRE.begin();

  return true;
};

// Packet structure is START | RANDINT | DATA | STOP
// Keep in mind that the maximum buffer size is defined by MAX_BUFFER
bool SwitcherI2C::write(uint8_t * data, uint8_t dataSize) {
  uint8_t buffSize = dataSize + 3;
  Serial.println(buffSize);

  if (buffSize > MAX_BUFFER)
    return false;

  uint8_t buffer[buffSize];

  memcpy(buffer + 2, data, dataSize);
  buffer[0] = START;
  buffer[1] = (uint8_t)random(0, 127);
  buffer[buffSize - 1] = 255;


  SWITCHER_WIRE.beginTransmission(this->peripheralAddress);
  SWITCHER_WIRE.write(buffer, buffSize);
  SWITCHER_WIRE.endTransmission();

  return true;
};