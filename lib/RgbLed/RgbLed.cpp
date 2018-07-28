#include "Arduino.h"
#include "RgbLed.h"

RgbLed::RgbLed(int redPin, int greenPin, int bluePin)
{
  _redPin = redPin;
  _bluePin = bluePin;
  _greenPin = greenPin;

  pinMode(_redPin, OUTPUT);
  pinMode(_greenPin, OUTPUT);
  pinMode(_bluePin, OUTPUT);
}
void RgbLed::setRgbColor(int red, int green, int blue)
{
  analogWrite(_redPin, red);
  analogWrite(_greenPin, green);
  analogWrite(_bluePin, blue);
}

void RgbLed::setColor(Color color)
{
  switch (color)
  {
    case RED:    setRgbColor(255, 0, 0);
      break;
    case GREEN:  setRgbColor(0, 255, 0);
      break;
    case BLUE:   setRgbColor(0, 0, 255);
      break;
    case YELLOW: setRgbColor(255, 255, 0);
      break;
    case PURPLE: setRgbColor(80, 0, 80);
      break;
    case AQUA:   setRgbColor(0, 255, 255);
      break;
  }
}
