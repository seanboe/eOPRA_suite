#include "CommHandler.h"


CommHandler::CommHandler(){};

// To be redefined in child classes
bool CommHandler::init(){};

// To be redefined in child classes
bool CommHandler::checkReceive(){};

