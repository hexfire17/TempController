#ifndef Button_h
#define Button_h

#include "Arduino.h"

enum State {ON, OFF, RELEASED, PRESSED};

class Button
{
  public:
    Button(int pin);
    void update();
    State getState();
  private:
    int _pin;
    State _state;
};

#endif
