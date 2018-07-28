#include "Arduino.h"
#include "LinkedList.h"

LinkedList::LinkedList()
{
  head = nullptr;
  _tail = nullptr;
}

void LinkedList::insert(int value)
{
  // start list
  if (head == nullptr)
  {
     ListNode *head = new ListNode(value);
     this->head = head;
     this->_tail = head;
  }
  // add to the tail
  else
  {
    ListNode *newTail = new ListNode(value);
    this->_tail->next = newTail;
    this->_tail = newTail;
  }

  Serial.println(_tail->value);
}
