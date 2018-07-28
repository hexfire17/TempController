#ifndef LiquidCrystalDisplay_h
#define LiquidCrystalDisplay_h

#include "Arduino.h"
#include <LiquidCrystal.h>

class LiquidCrystalDisplay
{
  public:
    LiquidCrystalDisplay(int rs, int e, int d4, int d5,int d6 , int d7);
    void init(int cols, int rows);
    void clear();
    void print(char *message);
    void print(double d, int precision);
    void print(int i);
    void setCursor(int col, int row);
    void display();
  private:
    LiquidCrystal *_lcd;
};

#endif
