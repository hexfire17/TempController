#ifndef RunningAverage_h
#define RunningAverage_h

#include "Arduino.h"

class RunningAverage
{
  public:
    RunningAverage(int size);
    void insert(double d);
    double getAverage();
  private:
    void incrementIndex();

    double *_averageArr;
    int _len;
    int _index;
};

#endif
