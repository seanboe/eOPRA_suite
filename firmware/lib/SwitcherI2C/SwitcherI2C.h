#ifndef SWITCHER_I2C_H
#define SWITCHER_I2C_H

#include <Arduino.h>
#include <Wire.h>

#include <../CommCodes.h>

typedef struct {
  uint8_t port;
} SwitcherGlobalCommData;

class SwitcherI2C { 
  public:
    SwitcherI2C();
    bool init(uint8_t peripheralAddress, uint8_t intPin, SwitcherGlobalCommData * commData);
    bool write(uint8_t * data, uint8_t dataSize);
    void receive(uint8_t bytes);
    void answerRequest();
    void interruptSwitcher();

    TwoWire getWireInstance();

    uint8_t decode(uint8_t * buffer, uint8_t buffSize, uint8_t * decoded);
    uint8_t encode(uint8_t * data, uint8_t dataSize, uint8_t * encoded, uint8_t randInt);

  private:

    SwitcherGlobalCommData * commData;

    uint8_t intPin;
    uint8_t commandQueue;
    bool dataQueued;
    uint8_t prevRandCheck;


};

#endif // SWITCHER_I2C_H
