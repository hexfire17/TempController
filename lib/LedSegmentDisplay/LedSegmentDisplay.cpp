#include "Arduino.h"
#include "LedSegmentDisplay.h"

int _configByInt[10][10]={
               {0,0,0,1,1,1,0,1,1,1},  //0
               {0,0,0,1,0,0,0,0,0,1},  //1
               {0,0,0,0,1,1,1,0,1,1},  //2
               {0,0,0,1,1,0,1,0,1,1},  //3
               {0,0,0,1,0,0,1,1,0,1},  //4
               {0,0,0,1,1,0,1,1,1,0},  //5
               {0,0,0,1,1,1,1,1,1,0},  //6
               {0,0,0,1,0,0,0,0,1,1},  //7
               {0,0,0,1,1,1,1,1,1,1},  //8
               {0,0,0,1,1,0,1,1,1,1}}; //9

LedSegmentDisplay::LedSegmentDisplay(int dp, int c, int d, int e, int g, int f, int a, int b)
{
  _segments = LinkedList();
  _segments.insert(dp);
  _segments.insert(c);
  _segments.insert(d);
  _segments.insert(e);
  _segments.insert(g);
  _segments.insert(f);
  _segments.insert(a);
  _segments.insert(b);

  ListNode *curr = _segments.head;
  while (curr != nullptr)
  {
    int currPin = curr->value;
    pinMode(currPin, OUTPUT);
    curr = curr->next;
  }
}

void LedSegmentDisplay::print(int value)
{
  ListNode *curr = _segments.head->next; // skip the decimal pin
  while (curr != nullptr)
  {
    int currPin = curr->value;
    digitalWrite(currPin, _configByInt[value][currPin]);
    curr = curr->next;
  }
}

void LedSegmentDisplay::setDecimal(int binaryVal)
{
  // garbage lazy code here...
  int decimalPin = _segments.head->value;
  digitalWrite(decimalPin, binaryVal);
}
