#ifndef RgbLed_h
#define RgbLed_h

#include "Arduino.h"

enum Color {RED, GREEN, BLUE, YELLOW, PURPLE, AQUA};

class RgbLed
{
  public:
    RgbLed(int redPin, int greenPin, int bluePin);
    void setRgbColor(int red, int green, int blue);
    void setColor(Color color);
  private:
    int _redPin;
    int _greenPin;
    int _bluePin;
};

#endif
