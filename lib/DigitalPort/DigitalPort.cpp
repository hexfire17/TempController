#include "Arduino.h"
#include "DigitalPort.h"

DigitalPort::DigitalPort(int pin)
{
  // initialize the digital pin as an output
  pinMode(pin, OUTPUT);
  _pin = pin;
  _currVoltage = LOW;
}

void DigitalPort::flipState()
{
  if (_currVoltage == LOW)
    on();
  else
    off();
}

void DigitalPort::on()
{
  // high voltage signals on
  _currVoltage = HIGH;
  digitalWrite(_pin, _currVoltage);
}

void DigitalPort::off()
{
  // low voltage singnals off
  _currVoltage = LOW;
  digitalWrite(_pin, _currVoltage);
}
