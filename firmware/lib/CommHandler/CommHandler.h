#ifndef COMM_HANDLER_H
#define COMM_HANDLER_H

#include <Arduino.h>

class CommHandler {
  public:
    CommHandler();

    virtual bool init();
    virtual bool receiveRespond(uint8_t receive_respond);

  private:
    void decode();
    uint8_t * encode(uint8_t * buffer);

};


#endif