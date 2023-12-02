#ifndef COMM_HANDLER_H
#define COMM_HANDLER_H

#include <Arduino.h>
#include <../CommCodes.h>

typedef struct {
  uint8_t stimPort;
} MainGlobalCommData;

class CommHandler {
  public:
    CommHandler();
    bool init(MainGlobalCommData * mainGlobalCommData);
    uint8_t decode(uint8_t * buffer, uint8_t buffSize, uint8_t * decoded);
    uint8_t encode(uint8_t * buffer, uint8_t buffSize, uint8_t * encoded, uint8_t randint=0xFF);
    uint8_t answerCommand(uint8_t);
    void setCommand(uint8_t command, uint8_t data);

  protected:
    // void decode();
    // uint8_t * encode(uint8_t * buffer);

    uint8_t prevRandCheck;
    bool setRequest;
    uint8_t awaitCommand;
    uint8_t prevTransmitAddr;

  private:
    MainGlobalCommData * mainGlobalCommData;

};


#endif