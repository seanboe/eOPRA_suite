#ifndef SWITCHER_I2C_H
#define SWITCHER_I2C_H

#include <Arduino.h>
#include <Wire.h>

#include <../CommCodes.h>

class SwitcherI2C { 
  public:
    SwitcherI2C();

    bool init(uint8_t peripheralAddress);

    bool write(uint8_t * data, uint8_t dataSize);

  private:

    uint8_t peripheralAddress;

};

#endif // SWITCHER_I2C_H
