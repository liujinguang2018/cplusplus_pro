#ifndef __BINARY_SEARCH_TREE_H__
#define __BINARY_SEARCH_TREE_H__

#include <queue>
#include <iostream>
using namespace std;

template<typename T>
class Queue : public queue<T>
{
    public:
        T dequeue() {
            T tmp = front();
            pop();

            return tmp;
        }

        void enqueue(const T& el)
        {
            push(el);
        }
};

template <typename T>
class BSTNode
{
  public:
    BSTNode()
    {
        left = right = nullptr;
    }

    BSTNode(const T &e, BSTNode<T> *l = nullptr, BSTNode<T> *r = nullptr)
    {
        el = e;
        left = l;
        right = r;
    }
    T el;
    BSTNode *left, *right;
};

template <typename T>
class BST
{
  public:
    BST() { root = nullptr; }

    void clear()
    {
        clear(root);
        root = nullptr;
    }

  protected:
    BSTNode<T> *root;
    void breadthFirst();
    void clear(BSTNode<T> *);
    T *search(BSTNode<T> *, const T &) const;
    virtual void visit(BSTNode<T> *p) {
        cout << p->el << " ";
    }
};

template <typename T>
void BST<T>::clear(BSTNode<T> *p)
{
    if (p != nullptr)
    {
        clear(p->left);
        clear(p->right);

        delete p;
    }
}

template <typename T>
T *search(BSTNode<T> *p, const T &el) const
{
    while (p != nullptr)
    {
        if (el == p->el)
        {
            return &p->el;
        }
        else if (el < p->el)
        {
            p = p->left;
        }
        else
        {
            p = p->right;
        }
    }

    return nullptr;
}

template<typename T>
void BST<T>::breadthFirst()
{
    Queue<BSTNode<T> *> queue;
    BSTNode<T> *P = root;

    if (p != nullptr) {
        queue.enqueue(p);
        while (!queue.empty()) {
            p = queue.dequeue();
            visit(p);
            if (p->left != nullptr) {
                queue.enqueue(p->left);
            }

            if (p->right != nullptr) {
                queue.enqueue(p->right);
            }
        }
    }
}

#endif