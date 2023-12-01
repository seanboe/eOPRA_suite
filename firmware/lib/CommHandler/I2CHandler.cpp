#include "I2CHandler.h"

I2CHandler::I2CHandler() {};

bool I2CHandler::init() {

  // Look inside `Wire.cpp` for pin fuckery
  // Wire 0 is used for commanding the device
  Wire1.begin();

  return true;
}


bool I2CHandler::request(uint8_t addr, uint8_t * commands, uint8_t lenCommands, uint8_t reqSize) {

  uint8_t buffSize = lenCommands + 3;

  if (buffSize > MAX_BUFFER)
    return false;

  uint8_t buffer[buffSize];

  this->prevRandCheck = this->encode(commands, lenCommands, buffer);

  Wire1.beginTransmission(addr);
  Wire1.write(buffer, buffSize);
  Wire1.endTransmission();

  this->awaitingData = true;

  this->awaitCommand = commands[0];

  delay(5);

  // Request from is blocking, so the slave can take some time to process the receive and respond to the request
  if (!Wire1.requestFrom(addr, reqSize))
    return false;

  return true;

}

bool I2CHandler::checkResponse() {
  if (!this->awaitingData)
    return false;

  if (Wire.available()) {

    uint8_t buffSize = Wire.available();

    if (buffSize > MAX_BUFFER)
      return false;

    uint8_t buffer[buffSize];
    Wire.readBytes(buffer, buffSize);

    uint8_t data[buffSize - 3];
    uint8_t randInt = this->decode(buffer, buffSize, data);

    if (randInt != this->prevRandCheck)
      return false;

    this->setCommand(this->awaitCommand, data[0]);

  }

}




// bool I2CHandler::onRequest(uint8_t * data, uint8_t len) {
//   this->port = port;

//   if (data[0] != START)
//     return false;

//   uint8_t dataQueue[len - 3];
//   memset(dataQueue, 0, len - 3);

//   for (int x = 0; x < len - 3; x++) {
//     if ((uint8_t)data[x + 2] == STOP) {
//       break;
//     }
//     dataQueue[x] = (uint8_t)data[x + 2];
//   }
  

