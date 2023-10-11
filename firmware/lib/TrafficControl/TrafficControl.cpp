#include "TrafficControl.h"

// See later: https://community.platformio.org/t/how-to-run-freertos-only-on-first-core-on-the-esp32-wroom-framework-is-esp-idf/26472

TrafficControl::TrafficControl() {};

bool TrafficControl::init(int baudrate) {

  Serial.begin(baudrate);

  return true;
};

bool TrafficControl::checkReceive() {
  if (Serial.available() > 0) {

    if (Serial.available() > MAX_BUFFER) {
      return false;
    }

    uint8_t buffSize = Serial.available();
    char buffer[buffSize];
    memset(buffer, 0, buffSize);
    Serial.readBytes(buffer, buffSize);

    if ((uint8_t)buffer[0] != START) {
      return false;
    }

    char randCheckChar[] = {buffer[1], '\0'};
    uint8_t randCheck = atoi(randCheckChar);

    uint8_t dataQueue[buffSize - 3]; // 3 Accounts for the start, check, and stop 
    memset(dataQueue, 0, buffSize - 3);

    for (int x = 0; x < buffSize - 3; x++) {
      if ((uint8_t)buffer[x + 2] == STOP) {
        break;
      }
      dataQueue[x] = (uint8_t)buffer[x + 2];
    }

    Serial.write((char *)dataQueue);

    delay(1000);
  };
  return true;
};


void TrafficControl::execute(uint8_t * dataQueue) {

}
