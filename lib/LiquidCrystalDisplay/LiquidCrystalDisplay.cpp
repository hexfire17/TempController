#include "Arduino.h"
#include "LiquidCrystalDisplay.h"

LiquidCrystalDisplay::LiquidCrystalDisplay(int rs, int e, int d4, int d5,int d6 , int d7)
{
  _lcd = new LiquidCrystal(rs, e, d4, d5, d6, d7);
}

void LiquidCrystalDisplay::init(int cols, int rows)
{
  _lcd->begin(16,2);
}

void LiquidCrystalDisplay::clear()
{
  _lcd->clear();
}

void LiquidCrystalDisplay::print(char *message)
{
  _lcd->print(message);
}

void LiquidCrystalDisplay::print(int i)
{
  _lcd->print(i);
}

void LiquidCrystalDisplay::print(double d, int precision)
{
   int beforeDecimal = d;
   _lcd->print(beforeDecimal);

   if (precision <= 0)
     return;

   _lcd->print(".");

   double whatsLeft = d - beforeDecimal;
   for (int p = 0; p < precision; p++)
   {
      int currPrecision = whatsLeft * 10;
      _lcd->print(currPrecision);
      whatsLeft = whatsLeft * 10 - currPrecision;
   }
}

void LiquidCrystalDisplay::setCursor(int col, int row)
{
  _lcd->setCursor(col, row);
}

void LiquidCrystalDisplay::display()
{
  _lcd->display();
}
