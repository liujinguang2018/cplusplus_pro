//singly-linked list class to store integers
#ifndef __INT_SINGLE_LIST_H__
#define __INT_SINGLE_LIST_H__

class IntSLLNode
{
  public:
    IntSLLNode()
    {
        next = nullptr;
    }

    IntSLLNode(int el, IntSLLNode *ptr = nullptr)
    {
        info = el;
        next = ptr;
    }

    int info;
    IntSLLNode *next;
};

class IntSLList
{
  public:
    IntSLList()
    {
        head = tail = nullptr;
    }

    ~IntSLList();

    inline bool isEmpty()
    {
        return head == nullptr;
    }

    void addToHead(int);
    void addToTail(int);

    int deleteFromHead();
    int deleteFromTail();
    void deleteNode(int);
    bool isInList(int) const;
    void printAll() const;

  private:
    IntSLLNode *head, *tail;
};

#endif