#include "I2CHandler.h"

I2CHandler::I2CHandler() {};

bool I2CHandler::init(uint8_t address) {

  // Look inside `Wire.cpp` for pin fuckery
  // Wire 0 is used for commanding the device
  Wire.begin(address);

  return true;
}

void I2CHandler::receive() {




}
