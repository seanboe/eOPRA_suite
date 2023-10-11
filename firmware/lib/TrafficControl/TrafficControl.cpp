#include "TrafficControl.h"

TrafficControl::TrafficControl() {};

bool TrafficControl::init(int baudrate) {

  Serial.begin(baudrate);

  return true;
};

bool TrafficControl::checkReceive() {
  if (Serial.available()) {

    if (Serial.available() > MAX_BUFFER) {
      return false;
    }

    uint8_t buffSize = Serial.available();
    char buffer[buffSize];
    memset(buffer, 0, buffSize);
    Serial.println("4");

    // Serial.readBytes(buffer, buffSize);
    // Serial.println(buffer);

    char start[2] = {buffer[0], '\0'};
    // Serial.println(buffer);

    if (atoi(start) != START) {
      return false;
    }

    char randCheckChar[] = {buffer[1], '\0'};
    uint8_t randCheck = atoi(randCheckChar);

    // Serial.write(String(randCheck, 3).c_str());

    // uint8_t dataQueue[MAX_BUFFER];
    // memset(dataQueue, STOP, MAX_BUFFER);

    // for (int x = 2; x < buffSize; x++) {  
    //   dataQueue[x - 2] = (uint8_t) atoi((char[]){buffer[x], '\0'});
    // }

    delay(1000);
  };
  return true;
};


void TrafficControl::execute(uint8_t * dataQueue) {
  Serial.write(dataQueue[0]);
}
