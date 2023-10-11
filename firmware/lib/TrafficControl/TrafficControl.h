#ifndef TRAFFIC_CONTROL_H
#define TRAFFIC_CONTROL_H

#include <Arduino.h>
#include "CommCodes.h"

#define MAX_BUFFER  10

class TrafficControl {
  public:
    TrafficControl();

    bool init(int baudrate);

    bool checkReceive();

  private:

    void execute(uint8_t * dataQueue);

};


#endif