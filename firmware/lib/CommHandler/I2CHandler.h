#ifndef I2C_HANDLER_H
#define I2C_HANDLER_H

#include <Arduino.h>
#include <Wire.h>

#include <../CommCodes.h>

// Still under construction!

// #include "CommHandler.h"

// For now, set I2C Handler up only to be a peripheral to another device without responses

class I2CHandler {
  public:
    I2CHandler();

    bool init(uint8_t address);

    bool onRequest(uint8_t * data, uint8_t len);

  private:

    volatile uint8_t port;


};


#endif