#ifndef ShiftRegister_h
#define ShiftRegister_h

#include "Arduino.h"

class ShiftRegister
{
  public:
    ShiftRegister(int latchPin, int clockPin, int dataPin);
    void setBit(int index, int value);
    void update();
    void reset();
  private:
    byte _setVector;
    int _latchPin;
    int _clockPin;
    int _dataPin;
};

#endif
