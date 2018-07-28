#ifndef MultiLedSegmentDisplay_h
#define MultiLedSegmentDisplay_h

#include "Arduino.h"

class MultiLedSegmentDisplay
{
  public:
    MultiLedSegmentDisplay(int display0, int display1, int display2, int display3,
      int aSeg, int bSeg, int cSeg, int dSeg, int eSeg, int fSeg, int gSeg, int dp);
    void displayNumber(int num);
    void displayDigit(int index, int num);
    void setDecimal(int index, int val);
  private:
    void clearCurrentDisplay();
    void selectDisplay(int index);
    void setSegments(int a, int b, int c, int d, int e, int f, int g, int dp);

    int _aSeg;
    int _bSeg;
    int _cSeg;
    int _dSeg;
    int _eSeg;
    int _fSeg;
    int _gSeg;
    int _dp;

    int _display0;
    int _display1;
    int _display2;
    int _display3;

    int _dp0;
    int _dp1;
    int _dp2;
    int _dp3;

    int _delayMicroSeconds;
};

#endif
