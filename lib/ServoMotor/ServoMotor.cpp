#include "Arduino.h"
#include "ServoMotor.h"

#include <Servo.h>

// twelve servo objects can be created on most boards
ServoMotor::ServoMotor()
{
  _position = 0;
}

void ServoMotor::init(int pin)
{
  _servo.attach(pin);
}

void ServoMotor::setPosition(int position)
{
  _position = position;
  _servo.write(_position);
}
