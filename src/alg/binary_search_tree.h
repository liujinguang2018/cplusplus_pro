#ifndef __BINARY_SEARCH_TREE_H__
#define __BINARY_SEARCH_TREE_H__

#include <queue>
#include <stack>
#include <iostream>
using namespace std;

template <typename T>
class Stack : public stack<T>
{
  public:
    T pop();
};

template <typename T>
T Stack<T>::pop()
{
    T tmp = stack<T>::top();
    stack<T>::pop();

    return tmp;
}

template <typename T>
class Queue : public queue<T>
{
  public:
    T dequeue()
    {
        T tmp = queue<T>::front();
        queue<T>::pop();

        return tmp;
    }

    inline void enqueue(const T &el)
    {
        queue<T>::push(el);
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
class BinarySearchTree
{

  public:
    BinarySearchTree() { root = nullptr; }

    void clear()
    {
        clear(root);
        root = nullptr;
    }

    void preorder()
    {
        preorder(root);
    }

    void inorder()
    {
        inorder(root);
    }

    void postorder()
    {
        postorder(root);
    }

    void iterativePreorder();

    void iterativePostorder();

    void iterativeInorder();

    void insert(const T &el);

    void breadthFirst();

    void findAndDeleteByMerging(const T &el);

    void findAndDeleteByCopying(const T &el);

    void balance(T data[], int first, int last);

  protected:
    BSTNode<T> *root;

    void clear(BSTNode<T> *);
    T *search(BSTNode<T> *, const T &) const;
    void visit(BSTNode<T> *p)
    {
        cout << p->el << " ";
    }

    void deleteByMerging(BSTNode<T> *&node);

    void deleteByCopying(BSTNode<T> *&node);

    void preorder(BSTNode<T> *);
    void inorder(BSTNode<T> *);
    void postorder(BSTNode<T> *);
};

template <typename T>
void BinarySearchTree<T>::inorder(BSTNode<T> *pnode)
{
    if (pnode != nullptr)
    {
        inorder(pnode->left);
        visit(pnode);
        inorder(pnode->right);
    }
}

template <typename T>
void BinarySearchTree<T>::preorder(BSTNode<T> *pnode)
{
    if (pnode != nullptr)
    {
        visit(pnode);
        preorder(pnode->left);
        preorder(pnode->right);
    }
}

template <typename T>
void BinarySearchTree<T>::postorder(BSTNode<T> *pnode)
{
    if (pnode != nullptr)
    {
        postorder(pnode->left);
        postorder(pnode->right);
        visit(pnode);
    }
}

template <typename T>
void BinarySearchTree<T>::iterativePreorder()
{
    Stack<BSTNode<T> *> travStack;
    BSTNode<T> *p = root;
    if (p != nullptr)
    {
        travStack.push(p);

        while (!travStack.empty())
        {
            p = travStack.pop();
            visit(p);

            if (p->right != nullptr)
            {
                travStack.push(p->right);
            }

            if (p->left != nullptr)
            {
                travStack.push(p->left); //be on the top of the stack
            }
        }
    }
}

template <typename T>
void BinarySearchTree<T>::iterativePostorder()
{
    Stack<BSTNode<T> *> travStack;
    BSTNode<T> *p = root, *q = root;

    while (p != nullptr)
    {
        for (; p->left != nullptr; p = p->left)
        {
            travStack.push(p);
        }

        while (p->right == nullptr || p->right == q)
        {
            visit(p);

            q = p;
            if (travStack.empty())
            {
                return;
            }

            p = travStack.pop();
        }

        travStack.push(p);
        p = p->right;
    }
}

template <typename T>
void BinarySearchTree<T>::iterativeInorder()
{
    Stack<BSTNode<T> *> travStack;
    BSTNode<T> *p = root;

    while (p != nullptr)
    {
        while (p != nullptr) //stack the right child (if any)
        {
            if (p->right) //add the node itself when going to the left
            {
                travStack.push(p->right);
            }
            travStack.push(p);

            p = p->left;
        }

        p = travStack.pop();                              // pop a node with no left child
        while (!travStack.empty() && p->right == nullptr) //visit it and all nodes with no right child
        {
            visit(p);
            p = travStack.pop();
        }
        visit(p); //visit also the first node with a right child (if any)

        if (!travStack.empty())
        {
            p = travStack.pop();
        }
        else
        {
            p = nullptr;
        }
    }
}

template <class T>
void BinarySearchTree<T>::clear(BSTNode<T> *p)
{
    if (p != nullptr)
    {
        clear(p->left);
        clear(p->right);

        delete p;
    }
}

template <class T>
T *BinarySearchTree<T>::search(BSTNode<T> *p, const T &el) const
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

template <class T>
void BinarySearchTree<T>::breadthFirst()
{
    Queue<BSTNode<T> *> queue;
    BSTNode<T> *p = root;

    if (p != nullptr)
    {
        queue.enqueue(p);
        while (!queue.empty())
        {
            p = queue.dequeue();
            visit(p);
            if (p->left != nullptr)
            {
                queue.enqueue(p->left);
            }

            if (p->right != nullptr)
            {
                queue.enqueue(p->right);
            }
        }
    }
}

template <typename T>
void BinarySearchTree<T>::insert(const T &el)
{
    BSTNode<T> *p = root, *prev = nullptr;

    while (p != nullptr) //find a place for inserting new node
    {
        prev = p;

        if (el < p->el)
        {
            p = p->left;
        }
        else if (el > p->el)
        {
            p = p->right;
        }
        else
        {
            cout << "duplicated value " << el << endl;

            return;
        }
    }

    if (root == nullptr)
    {
        root = new BSTNode<T>(el);
    }
    else if (el < prev->el)
    {
        prev->left = new BSTNode<T>(el);
    }
    else
    {
        prev->right = new BSTNode<T>(el);
    }
}

//从被删除节点的两棵子树中得到一棵树，然后将这棵树连接到
//被删除节点的父节点处
//左子树中的最大值节点，使它成为右子树的父节点，或者
//右子树中的最小值节点，使它成为左子树的父节点
//node为父节点的左指针或右指针
template <typename T>
void BinarySearchTree<T>::deleteByMerging(BSTNode<T> *&node)
{
    BSTNode<T> *tmp = node;

    if (node != nullptr)
    {
        if (node->right != nullptr) //node has no right child: its left child (if any) is attached to its parent;
        {
            node = node->left;
        }
        else if (node->left != nullptr) //node has no left child: its right child is attached to its parent
        {
            node = node->right;
        }
        else //be ready for merging subtree
        {
            tmp = node->left; //1. move left
            while (tmp->right != nullptr)
            {
                tmp = tmp->right;
            }

            tmp->right = node->right;

            tmp = node;
            node = node->left;
        }

        delete tmp;
    }
}

template <typename T>
void BinarySearchTree<T>::findAndDeleteByMerging(const T &el)
{
    BSTNode<T> *node = root, *prev = nullptr;

    //查找对应节点
    while (node != nullptr)
    {
        if (node->el == el)
        {
            break;
        }

        prev = node;

        if (node->el < el)
        {
            node = node->right;
        }
        else
        {
            node = node->left;
        }
    }

    if (node != nullptr && node->el == el)
    {
        if (node == root)
        {
            deleteByMerging(root);
        }
        else if (prev->left == node)
        {
            deleteByMerging(prev->left);
        }
        else
        {
            deleteByMerging(prev->right);
        }
    }
    else if (root != nullptr)
    {
        cout << "el " << el << " is not in the tree" << endl;
    }
    else
    {
        cout << "the tree is empty" << endl;
    }
}

template <typename T>
void BinarySearchTree<T>::deleteByCopying(BSTNode<T> *&node)
{
    BSTNode<T> *tmp = node, *prev = nullptr;

    if (node->right == nullptr) //node has no right child
    {
        node = node->left;
    }
    else if (node->left == nullptr) //node has no left child
    {
        node = node->right;
    }
    else //node has both children
    {
        tmp = node->left;
        prev = node;

        while (tmp->right != nullptr)
        {
            prev = tmp;
            tmp = tmp->right;
        }

        node->el = tmp->el;

        if (prev == node)
        {
            prev->left = tmp->left;
        }
        else
        {
            prev->right = tmp->left;
        }

        delete tmp;
    }
}

template <typename T>
void BinarySearchTree<T>::findAndDeleteByCopying(const T &el)
{
    BinarySearchTree<T> *p = root, *prev = nullptr;

    while (p != nullptr && p->el != el)
    {
        prev = p;
        if (el < p->el)
        {
            p = p->left;
        }
        else
        {
            p = p->right;
        }
    }

    if (p != nullptr && p->el == el)
    {
        if (p == root)
        {
            deleteByCopying(root);
        }
        else if (prev->left == p)
        {
            deleteByCopying(prev->left);
        }
        else
        {
            deleteByCopying(prev->right);
        }
    }
    else if (root != nullptr)
    {
        cout << "el " << el << " is not in the tree" << endl;
    }
    else
    {
        cout << "the tree is empty" << endl;
    }
}


//中序遍历后，得到升序排列数组，然后调用balance重构
template <typename T>
void BinarySearchTree<T>::balance(T data[], int first, int last)
{
    if (first <= last)
    {
        int mid = (first + last) / 2;
        insert(data[mid]);

        balance(data, first, mid - 1);
        balance(data, mid + 1, last);
    }
}

#endif
