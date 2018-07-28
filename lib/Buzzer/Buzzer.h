#ifndef Buzzer_h
#define Buzzer_h

#include "Arduino.h"

class Buzzer
{
  public:
    Buzzer(int pin);
    void playTone(int frequencyHz, int durationMs);
    void playToneAsync(int frequencyHz, int durationMs);
  private:
    int _pin;
};

#endif
