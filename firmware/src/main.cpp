#include <Arduino.h>

#include <PinDefs.h>
#include <TrafficControl.h>

TrafficControl trafficController = TrafficControl();

void setup() {

  // while(!Serial) {
  //   ;
  // }

  // Serial.println(5, HEX);
  
  // while(!Serial.available()) {
  //   ;
  // }
  // Serial.println("right here");

  // char comm_buffer[Serial.available()];

  // Serial.println(Serial.available());

  // Serial.println(sizeof(comm_buffer) / sizeof(char));

  // Serial.println(comm_buffer);

  trafficController.init(112500);


}

void loop() {

  trafficController.checkReceive();
  // Serial.println("hi");


  // if (Serial.available() > 0) {
  //   char comm_buffer[Serial.available()];
  //   Serial.println(Serial.available());

  //   Serial.println(sizeof(comm_buffer) / sizeof(char));

  //   uint16_t a = (uint16_t)comm_buffer[0, sizeof(comm_buffer) / sizeof(char)];

  //   Serial.println(a, HEX);
  // }

  // if (digitalRead(ENCODER_A) != aHigh) {
  //   if (digitalRead(ENCODER_A) && !digitalRead(ENCODER_B)) {
  //     position += 1;
  //   }
  //   else if (digitalRead(ENCODER_A) && digitalRead(ENCODER_B)) {
  //     position -= 1
  //   }
  //   aHigh = digitalRead(ENCODER_A);
  // }



}