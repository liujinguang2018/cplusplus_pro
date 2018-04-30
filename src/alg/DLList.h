#ifndef __DOUBLE_LINKED_LIST_H__
#define __DOUBLE_LINKED_LIST_H__

template <typename T>
class DLLNode
{
  public:
    DLLNode()
    {
        prev_ = next_ = nullptr;
    }

    DLLNode(const T &el, DLLNode<T> *next, DLLNode<T> *prev)
    {
        info_ = el;
        prev_ = prev;
        next_ = next;
    }

    T info_;
    DLLNode *prev_, *next_;
};


template<typename T>
class DoubleLinkedList {
    public:
        DoubleLinkedList() {
            head_ = tail_ = nullptr;
        }

    protected:
        DLLNode<T> *head_, *tail_;
};

#endif