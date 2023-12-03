#ifndef UTILITIES_H
#define UTILITIES_H

#include <Arduino.h>
#include "PinDefs.h"

bool setStimulationPort(uint8_t port) {
  if (port > 7)
    return false;

  if (port & 0x01)
    digitalWrite(ENC_CTL_0, HIGH);
  if (port & 0x02)
    digitalWrite(ENC_CTL_1, HIGH);
  if (port & 0x04)
    digitalWrite(ENC_CTL_2, HIGH);

  return true;
}


#endif