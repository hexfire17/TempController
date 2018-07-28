#ifndef ServoMotor_h
#define ServoMotor_h

#include "Arduino.h"
#include <Servo.h>

class ServoMotor
{
  public:
    ServoMotor();
    void init(int pin);
    void setPosition(int position);
  private:
    Servo _servo;
    int _position;
};

#endif
