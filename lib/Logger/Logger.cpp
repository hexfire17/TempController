#include "Arduino.h"
#include "Logger.h"

// NOTE:
// when the logger is used, digital pins 0 and 1 are used for communication
Logger::Logger()
{
}

void Logger::init()
{
  Serial.begin(9600);
}

void Logger::log(char *label, int value)
{
  Serial.print(label);
  Serial.println(value);
}

void Logger::log(char *label, double value)
{
  Serial.print(label);
  Serial.println(value);
}
