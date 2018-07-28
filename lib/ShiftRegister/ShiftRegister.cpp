#include "Arduino.h"
#include "ShiftRegister.h"

ShiftRegister::ShiftRegister(int latchPin, int clockPin, int dataPin)
{
  _latchPin = latchPin;
  _clockPin = clockPin;
  _dataPin = dataPin;

  pinMode(_latchPin, OUTPUT);
  pinMode(_dataPin, OUTPUT);
  pinMode(_clockPin, OUTPUT);

  reset();
}

void ShiftRegister::update()
{
  digitalWrite(_latchPin, LOW);
  shiftOut(_dataPin, _clockPin, LSBFIRST, _setVector);
  digitalWrite(_latchPin, HIGH);
}

void ShiftRegister::setBit(int index, int value)
{
  if (value == 1)
    bitSet(_setVector, index);
  else
    bitClear(_setVector, index);

  update();
}

void ShiftRegister::reset()
{
  _setVector = 0;
  update();
}
