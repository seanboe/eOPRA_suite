#include <Arduino.h>
#include "PinDefs.h"

#include <Wire.h>
#include <../lib/CommCodes.h>
#include "utilities.h"


// void requestEvent();
// void receiveEvent(int bytes);

volatile bool ISRTriggered;
volatile bool port;
volatile long timer;

void ISRHandler() {
  // Serial.println("hello");
  if (ISRTriggered)
    return;

  port = !port;

  if (port) {
    // port 2
    digitalWrite(ENC_CTL_0, LOW);
    digitalWrite(ENC_CTL_1, HIGH);
    digitalWrite(ENC_CTL_2, LOW);
  }
  else {
    // port 5
    digitalWrite(ENC_CTL_0, HIGH);
    digitalWrite(ENC_CTL_1, LOW);
    digitalWrite(ENC_CTL_2, HIGH);
  }

  ISRTriggered = true;
}

void setup() {
  // Wire.setSDA(MASTER_SDA0);
  // Wire.setSCL(MASTER_SCL0);
  Serial.begin(9600);
  // Wire.begin(8);                // join i2c bus with address #8
  // Wire.onRequest(requestEvent); // register event
  // Wire.onReceive(receiveEvent);
  port = true;


  pinMode(A_IN_2_PIN, INPUT_PULLUP);
  pinMode(ENC_CTL_0, OUTPUT);
  pinMode(ENC_CTL_1, OUTPUT);
  pinMode(ENC_CTL_2, OUTPUT);

  ISRTriggered = false;
  timer = micros();


  // setStimulationPort()
  attachInterrupt(digitalPinToInterrupt(A_IN_2_PIN), ISRHandler, FALLING);


}

void loop() {

  if (ISRTriggered) {
    Serial.print("Triggered | ");
    Serial.print(micros() - timer);
    timer = micros();

    if (port)
      Serial.println(" | 5");
    else 
      Serial.println(" | 7");

  }
  ISRTriggered = false;

}

// void receiveEvent(int bytes) {
//   if (Wire.available()) {
//     port = Wire.read();
//   }
// }

















// #include <SwitcherI2C.h>

// // SwitcherI2C switcher = SwitcherI2C();

// void setup1() {
//   // Wire.setSDA(MASTER_SDA0);
//   // Wire.setSCL(MASTER_SCL0);
//   Wire1.begin();        // join i2c bus (address optional for master)
//   // switcher.init(8);
//   // Serial.begin(9600);  // start serial for output
// }

// void loop1() {

//   // uint8_t data = {10};
//   // switcher.write(&data);

//   Wire1.beginTransmission(8);
//   Wire1.write(10);
//   Wire1.endTransmission();
//   // // Serial.println("Sent hello!");

//   // // Wire1.requestFrom(8, 6);    // request 6 bytes from peripheral device #8

//   // while (Wire1.available()) { // peripheral may send less than requested
//   //   char c = Wire1.read(); // receive a byte as character
//   //   Serial.print(c);         // print the character
//   // }

//   delay(500);
// }