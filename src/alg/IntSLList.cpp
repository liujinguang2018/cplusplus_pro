#include <iostream>
#include "intSLList.h"

using namespace std;

IntSLList::~IntSLList()
{
    IntSLLNode *ptr;

    while (!isEmpty())
    {
        ptr = head->next;
        delete head;
        head = ptr;
    }
}

void IntSLList::addToHead(int val)
{
    head = new IntSLLNode(val, head);
    if (tail == nullptr)
    {
        tail = head;
    }
}

void IntSLList::addToTail(int val)
{
    if (tail != nullptr)
    {
        tail->next = new IntSLLNode(val);
        tail = tail->next;
    }
    else
    {
        head = tail = new IntSLLNode(val);
    }
}

int IntSLList::deleteFromHead()
{
    if (!isEmpty())
    {
        int val = head->info;
        IntSLLNode *ptr = head;

        if (head == tail)
        { //only one element
            head = tail = nullptr;
        }
        else
        {
            head = head->next;
        }

        delete ptr;

        return val;
    }
    else
    {
        return 0;
    }
}

int IntSLList::deleteFromTail()
{
    int val = tail->info;

    if (head == tail) // if only one node on the list;
    {
        delete head;

        head = tail = nullptr;
    }
    else
    {
        IntSLLNode *tmp;
        for (tmp = head; tmp->next != tail; tmp = tmp->next)
        {
            ;
        }
        tmp->next = nullptr;
        delete tail;
        tail = tmp;
    }

    return val;
}

void IntSLList::deleteNode(int val)
{
    if (isEmpty()) //empty list, just return here
    {
        return;
    }

    if (head == tail)
    { // if only one node on the list;
        if (head->info == val)
        {
            delete head;
            head = tail = nullptr;
        }

        return;
    }

    IntSLLNode *tmp = head;
    if (head->info == val)
    {
        head = head->next;

        delete tmp;

        return;
    }

    for (; tmp->next->info != val; tmp = tmp->next)
    {
        if (tmp == nullptr) ///
        {
            return;
        }
    }

    IntSLLNode *node = tmp->next;
    if (tail == node)
    {
        tail = tmp;
        tmp->next = nullptr;
    }
    else
    {
        tmp->next = tmp->next->next;
    }

    delete node;
}

bool IntSLList::isInList(int val) const
{
    IntSLLNode *tmp;
    for (tmp = head; tmp != nullptr && tmp->info != val; tmp = tmp->next)
    {
        ;
    }

    if (tmp == nullptr)
    {
        return false;
    }
    else
    {
        return true;
    }
}

void IntSLList::printAll() const
{
    for (IntSLLNode *tmp = head; tmp != 0; tmp = tmp->next)
    {
        std::cout << tmp->info << " ";
    }
    std::cout << std::endl;
}