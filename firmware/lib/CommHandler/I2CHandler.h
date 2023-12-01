#ifndef I2C_HANDLER_H
#define I2C_HANDLER_H

#include <Arduino.h>
#include <Wire.h>

#include <../CommCodes.h>

// Still under construction!

#include "CommHandler.h"

class I2CHandler : CommHandler {
  public:
    I2CHandler();

    bool init();

    // bool onRequest(uint8_t * data, uint8_t len);
    bool request(uint8_t addr, uint8_t * commands, uint8_t lenCommands, uint8_t reqSize);

    bool checkResponse();

  private:

    volatile uint8_t port;


};


#endif