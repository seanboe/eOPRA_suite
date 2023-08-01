#include <Arduino.h>


#define ENCODER_A   1
#define ENCODER_B   2

bool aHigh;

long position;

void setup() {
  // put your setup code here, to run once:

  pinMode(ENCODER_A, INPUT);
  pinMode(ENCODER_A, INPUT);

  a = digitalRead(aHigh);
  b = digitalRead(bHigh);

  position = 0;

}

void loop() {

  if (digitalRead(ENCODER_A) != aHigh) {
    if (digitalRead(ENCODER_A) && !digitalRead(ENCODER_B)) {
      position += 1;
    }
    else if (digitalRead(ENCODER_A) && digitalRead(ENCODER_B)) {
      position -= 1
    }
    aHigh = digitalRead(ENCODER_A);
  }



}