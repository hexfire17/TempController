#include "Arduino.h"
#include "Buzzer.h"

Buzzer::Buzzer(int pin)
{
  _pin = pin;
}

void Buzzer::playTone(int frequencyHz, int durationMs)
{
  tone(_pin, frequencyHz, durationMs);
  delay(durationMs);
}

void Buzzer::playToneAsync(int frequencyHz, int durationMs)
{
  tone(_pin, frequencyHz, durationMs);
}
