#ifndef ListNode_h
#define ListNode_h

struct ListNode
{
    ListNode::ListNode(int value)
    {
      this->value = value;
      this->next = nullptr;
    }

    struct ListNode *next;
    int value;
};

class LinkedList
{
  public:
    LinkedList();
    void insert(int value);
    struct ListNode *head;
  private:
    struct ListNode *_tail;
};

#endif
