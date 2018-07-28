#include "Arduino.h"
#include "MultiLedSegmentDisplay.h"

/*
  Showing number 0-9 on a Common Anode 7-segment LED display
  this thing display from left to right, setting each display reaally
  fast, change the delay to adjust speed of shifting, like framerate kinda
  Below is the layout:
    A
   ---
F |   | B
  | G |
   ---
E |   | C
  |   |
   ---
    D

    // TODO decimal setting / parsing
 */
 int _configByInt[13][7]={
                {0,0,0,0,0,0,1},  //0
                {1,0,0,1,1,1,1},  //1
                {0,0,1,0,0,1,0},  //2
                {0,0,0,0,1,1,0},  //3
                {1,0,0,1,1,0,0},  //4
                {0,1,0,0,1,0,0},  //5
                {0,1,0,0,0,0,0},  //6
                {0,0,0,1,1,1,1},  //7
                {0,0,0,0,0,0,0},  //8
                {0,0,0,0,1,0,0},  //9
                {0,1,1,1,0,0,0},  // 10- F
                {1,1,1,1,1,1,1},  //11 - blank
                {1,1,1,1,1,1,0}}; //12 - -


int _dpConfigByDisplay[4]={1,1,1,1};

MultiLedSegmentDisplay::MultiLedSegmentDisplay(
  int display0, int display1, int display2, int display3,
  int aSeg, int bSeg, int cSeg, int dSeg, int eSeg, int fSeg, int gSeg, int dp)
{
  _display0 = display0;
  _display1 = display1;
  _display2 = display2;
  _display3 = display3;
  _aSeg = aSeg;
  _bSeg = bSeg;
  _cSeg = cSeg;
  _dSeg = dSeg;
  _eSeg = eSeg;
  _fSeg = fSeg;
  _gSeg = gSeg;
  _dp = dp;

  _delayMicroSeconds = 500;

  _dp0 = 1;
  _dp1 = 1;
  _dp2 = 1;
  _dp3 = 1;

  pinMode(_display0, OUTPUT);
  pinMode(_display1, OUTPUT);
  pinMode(_display2, OUTPUT);
  pinMode(_display3, OUTPUT);
  pinMode(_aSeg, OUTPUT);
  pinMode(_bSeg, OUTPUT);
  pinMode(_cSeg, OUTPUT);
  pinMode(_dSeg, OUTPUT);
  pinMode(_eSeg, OUTPUT);
  pinMode(_fSeg, OUTPUT);
  pinMode(_gSeg, OUTPUT);
  pinMode(_dp, OUTPUT);
}

void MultiLedSegmentDisplay::clearCurrentDisplay()
{
   digitalWrite(_aSeg, HIGH);
   digitalWrite(_bSeg, HIGH);
   digitalWrite(_cSeg, HIGH);
   digitalWrite(_dSeg, HIGH);
   digitalWrite(_eSeg, HIGH);
   digitalWrite(_fSeg, HIGH);
   digitalWrite(_gSeg, HIGH);
   digitalWrite(_dp, HIGH);
}

// enables one display for segment writing
// we can change this later to write to multiple if we want
void MultiLedSegmentDisplay::selectDisplay(int index)
{
  digitalWrite(_display0, LOW);
  digitalWrite(_display1, LOW);
  digitalWrite(_display2, LOW);
  digitalWrite(_display3, LOW);

  switch(index)
  {
  case 0:
    digitalWrite(_display0, HIGH);
    break;
  case 1:
    digitalWrite(_display1, HIGH);
    break;
  case 2:
    digitalWrite(_display2, HIGH);
    break;
  case 3:
    digitalWrite(_display3, HIGH);
    break;
  }
}


// LOW or 0 is ON (anode stuff, don't understand yet...)
void MultiLedSegmentDisplay::setSegments(int a, int b, int c, int d, int e, int f, int g, int dp)
{
  digitalWrite(_aSeg, a);
  digitalWrite(_bSeg, b);
  digitalWrite(_cSeg, c);
  digitalWrite(_dSeg, d);
  digitalWrite(_eSeg, e);
  digitalWrite(_fSeg, f);
  digitalWrite(_gSeg, g);
  digitalWrite(_dp, dp);
}

void MultiLedSegmentDisplay::displayDigit(int index, int num)
{
  selectDisplay(index);
  setSegments(_configByInt[num][0],
              _configByInt[num][1],
              _configByInt[num][2],
              _configByInt[num][3],
              _configByInt[num][4],
              _configByInt[num][5],
              _configByInt[num][6],
              _dpConfigByDisplay[index]);

  delayMicroseconds(_delayMicroSeconds);  // Time adjustment
  clearCurrentDisplay();  // Eliminating ghost
}

void MultiLedSegmentDisplay::displayNumber(int num)
{
  int divider = 1000;
  for (int i = 3; i >= 0; i--)
  {
    int currDigit = num / divider;
    num = num - (divider * currDigit);
    divider = divider / 10;
    displayDigit(3-i, currDigit);
  }
}

void MultiLedSegmentDisplay::setDecimal(int index, int val)
{
  _dpConfigByDisplay[index] = val;
}
