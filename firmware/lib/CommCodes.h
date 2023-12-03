// ****** GENERATED ON COMPILE ******

#ifndef COMM_CODES_H
#define COMM_CODES_H

// Maximum buffer size for sending / receiving
#define MAX_BUFFER 10

// Meta Commands
#define START 0x01
#define COMMAND_BREAK 0x02
#define STOP 0xFF

// UART / EXTERNAL COMMANDS

// Set Commands
#define SET_PORT 0x10
#define SET_BROADCAST 0x11
#define SET_STIMULATION 0x12
#define SET_STREAM 0x13
#define SET_DEBUG 0x14
#define SET_DISPLAY 0x15
#define SET_BUZZER 0x16


// Get Commands
#define GET_TIME 0x50
#define GET_DEVICES 0x51
#define GET_STIMULATION_PORT 0x52
#endif