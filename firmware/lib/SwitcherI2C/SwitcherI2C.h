#ifndef SWITCHER_I2C_H
#define SWITCHER_I2C_H

#include <Arduino.h>
#include <Wire.h>
#include <CommHandler.h>

#include <../CommCodes.h>

typedef struct {
  uint8_t port;
} SwitcherGlobalCommData;

class SwitcherI2C : CommHandler { 
  public:
    SwitcherI2C();
    bool init(uint8_t peripheralAddress, uint8_t intPin, SwitcherGlobalCommData * commData);
    bool write(uint8_t * data, uint8_t dataSize);
    bool receive(uint8_t bytes);
    void answerRequest();
    void interruptSwitcher();

    TwoWire getWireInstance();

  private:

    SwitcherGlobalCommData * commData;

    uint8_t intPin;
    uint8_t commandQueue;
    bool dataQueued;


};

#endif // SWITCHER_I2C_H
