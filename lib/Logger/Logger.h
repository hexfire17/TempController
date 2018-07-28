#ifndef Logger_h
#define Logger_h

#include "Arduino.h"

class Logger
{
  public:
    Logger();
    void init();
    void log(char *label, int value);
    void log(char *label, double value);

};

#endif
