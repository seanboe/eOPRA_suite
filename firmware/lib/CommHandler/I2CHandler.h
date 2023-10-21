#ifndef I2C_HANDLER_H
#define I2C_HANDLER_H

#include <Arduino.h>
#include <Wire.h>

// #include "CommHandler.h"

// For now, set I2C Handler up only to be a peripheral to another device without responses

class I2CHandler {
  public:
    I2CHandler();

    bool init(uint8_t address);

    bool receive();

  private:

    void I2C_ISR();

  //   typedef CommHandler super;


};


#endif