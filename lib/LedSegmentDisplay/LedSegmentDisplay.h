#ifndef LedSegmentDisplay_h
#define LedSegmentDisplay_h

#include "Arduino.h"
#include <LinkedList.h>

class LedSegmentDisplay
{
  public:
    LedSegmentDisplay::LedSegmentDisplay(int dp, int c, int d, int e, int g, int f, int a, int b);
    void print(int value);
    void setDecimal(int binaryVal);
  private:
    LinkedList _segments;
};

#endif
