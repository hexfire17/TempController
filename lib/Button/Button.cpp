#include "Arduino.h"
#include "Button.h"

// START CONFIG
// ##########################
int onCycles = 50;
int offCycles = 50;
// ##########################
// END CONFIG

// GLOBALS
int onCount = 0;
int offCount = 0;

Button::Button(int pin)
{
  _pin = pin;
  pinMode(_pin, INPUT);
  _state = OFF;
}

void Button::update()
{
  int voltage = digitalRead(_pin);

  if (_state == PRESSED) // only one cycle of pressed
    _state = ON;

  if (_state == RELEASED) // only one cycle of released
    _state = OFF;

  if (_state != ON && voltage == HIGH)
    onCount++;
  if (_state != OFF && voltage == LOW)
    offCount++;

  if (onCount >= onCycles)
  {
    _state = PRESSED;
    onCount = 0;
    offCount = 0;
    Serial.println("PRESSED");
  }
  else if (offCount >= offCycles)
  {
    _state = RELEASED;
    onCount = 0;
    offCount = 0;
    Serial.println("RELEASED");
  }
}

State Button::getState()
{
  return _state;
}
