#include "I2CHandler.h"

I2CHandler::I2CHandler() {};

bool I2CHandler::init(MainGlobalCommData * commData) {

  CommHandler::init(commData);

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
  if (this->prevRandCheck == 0xFF)
    return false;

  Wire1.beginTransmission(addr);
  Wire1.write(buffer, buffSize);
  Wire1.endTransmission();

  this->setRequest = true;
  this->awaitCommand = commands[0];
  this->prevTransmitAddr = addr;

  return true;

}

bool I2CHandler::checkResponse() {
  if (this->setRequest)
    Wire1.requestFrom(this->prevTransmitAddr, 4);
    this->setRequest = false;

  if (Wire1.available()) {

    uint8_t buffSize = Wire1.available();

    if (buffSize > MAX_BUFFER)
      return false;

    uint8_t buffer[buffSize];
    Wire1.readBytes(buffer, buffSize);

    uint8_t data[buffSize - 3];
    uint8_t randInt = this->decode(buffer, buffSize, data);

    if (randInt != this->prevRandCheck)
      return false;

    this->setCommand(this->awaitCommand, data[0]);

    return true;
  }
  return false;
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
  

