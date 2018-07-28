#ifndef DigitalPort_h
#define DigitalPort_h

#include "Arduino.h"

class DigitalPort
{
  public:
    DigitalPort(int pin);
    void on();
    void off();
    void flipState();
  private:
    int _pin;
    int _currVoltage;
};

#endif
