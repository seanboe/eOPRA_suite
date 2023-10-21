#include "I2CHandler.h"

I2CHandler::I2CHandler() {};

bool I2CHandler::init(uint8_t address) {

  // Look inside `Wire.cpp` for pin fuckery
  // Wire 0 is used for commanding the device
  Wire.begin(address);

  return true;
}



bool I2CHandler::onRequest(uint8_t * data, uint8_t len) {
  this->port = port;

  if (data[0] != START)
    return false;

  uint8_t dataQueue[len - 3];
  memset(dataQueue, 0, len - 3);

  for (int x = 0; x < len - 3; x++) {
    if ((uint8_t)data[x + 2] == STOP) {
      break;
    }
    dataQueue[x] = (uint8_t)data[x + 2];
  }
  
  

}
