#ifndef PINDEFS_H
#define PINDEFS_H

// For board version 1

//**** COMMUNICATION ****

// SERIAL
#define EXT_TX        0
#define EXT_RX        1

// I2C
// Port on which switcher is the master
#define SLAVE_SDA1    18
#define SLAVE_SCL1    19

// Port on which switcher is a slave
#define MASTER_SDA0   20
#define MASTER_SCL0   21

// SPI
#define EXT_SWCK1      10
#define EXT_MOSI1      11
#define EXT_MISO1      12

// CAN
#define CAN_STBY      16
#define TX0RTS        17
#define CAN_INT       22
#define RX0BF         23
#define CAN_CS        28
#define CAN_RESET     27


//**** PERIPEHRALS ****

// ESP8266 INTERRUPT LINE
#define ESP_INT       7

// BUZZER
#define BUZZER        8

// TFT
#define TFT_DC        5
#define SD_CS         6
#define TFT_SCK0      2
#define TFT_MOSI0     3
#define TFT_MISO0     4
#define TFT_CS        9         // CAN ALSO ACT AS RP2040 SLAVE CS
#define TFT_RESET     -1        // -1 means unused

// DECODER
#define ENC_CTL_0     13
#define ENC_CTL_1     14
#define ENC_CTL_2     15

// ENCODER
#define ROT_ENC_0     24
#define ROT_ENC_1     25

// ANALOG IN
#define A_IN_2_PIN    26
#define A_IN_3_PIN    27

#endif