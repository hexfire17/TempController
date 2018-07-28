#include "Arduino.h"
#include "RunningAverage.h"

void RunningAverage::clear()
{
  for (int i = 0; i < _len; i++)
  {
    _averageArr[i] = -1;
  }
}

RunningAverage::RunningAverage(int size)
{
  _averageArr = new double[size];
  _len = size;
  _index = 0;
  clear();
}

void RunningAverage::incrementIndex()
{
  _index++;
  if (_index == _len)
    _index = 0;
}

void RunningAverage::insert(double d)
{
  _averageArr[_index] = d;
  incrementIndex();
}

double RunningAverage::getAverage()
{
  double sum = 0;
  int numExists = 0;
  for (int i = 0; i < _len; i++)
  {
    double curr = _averageArr[i];
    if (curr != -1)
    {
      sum+= curr;
      numExists++;
    }
  }
  return sum / numExists;
}
