#include "CommHandler.h"


CommHandler::CommHandler(){};

bool CommHandler::init(MainGlobalCommData * mainGlobalCommData) {
  this->prevRandCheck = 0xFF;
  this->awaitingData = false;
  this->awaitCommand = 0xFF;

  this->mainGlobalCommData = mainGlobalCommData;
}

// To be redefined in child classes
// bool CommHandler::receiveRespond(){};

uint8_t CommHandler::decode(uint8_t * buffer, uint8_t buffSize, uint8_t * decoded) {

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

uint8_t CommHandler::encode(uint8_t * data, uint8_t dataSize, uint8_t * encoded, uint8_t randInt) {

  if (dataSize + 3 > MAX_BUFFER)
    return 0xFF;

  memcpy(encoded + 2, data, dataSize);
  encoded[0] = START;

  if (randInt == 0xFF)
    encoded[1] = (uint8_t)random(0, 127);
  else
    encoded[1] = randInt;

  encoded[dataSize + 2] = STOP;

  return encoded[1];
};

uint8_t CommHandler::answerCommand(uint8_t command) {
  switch (command) {
    case GET_STIMULATION_PORT: return this->mainGlobalCommData->stimPort; break;
  }
}

uint8_t CommHandler::setCommand(uint8_t command, uint8_t data) {
    switch (command) {
    case GET_STIMULATION_PORT: this->mainGlobalCommData->stimPort = data; break;
  }
}