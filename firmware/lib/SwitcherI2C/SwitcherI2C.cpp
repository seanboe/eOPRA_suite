#include "SwitcherI2C.h"

SwitcherI2C::SwitcherI2C() {};

bool SwitcherI2C::init(uint8_t peripheralAddress) {

  this->peripheralAddress = peripheralAddress;

  // Uses port 0
  Wire.begin();

  return true;
};

// Packet structure is START | RANDINT | DATA | STOP
// Keep in mind that the maximum buffer size is defined by MAX_BUFFER
bool SwitcherI2C::write(uint8_t * data) {
  uint8_t buffSize = sizeof(data) / sizeof(uint8_t) + 3;

  // if (buffSize > MAX_BUFFER)
  //   return false;

  // uint8_t buffer[buffSize];

  // memcpy(buffer + 2, data, buffSize);
  // buffer[0] = START;
  // buffer[1] = (uint8_t)random(0, 127);
  // buffer[buffSize - 1] = STOP;
  
  Wire.beginTransmission(this->peripheralAddress);
  Wire.write(data, buffSize);
  Wire.endTransmission();

  return true;
};