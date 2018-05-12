#include "binary_search_tree.h"


//                     构建二叉树
//                        13
//                     /       \
//                   10         25
//                  /   \      /  \
//                 2    12    20  31
//                                /
//                               29


//template <typename T>
void constructTree(BinarySearchTree<int> &tree)
{
    tree.insert(13);
    tree.insert(10);
    tree.insert(25);
    tree.insert(2);
    tree.insert(12);
    tree.insert(20);
    tree.insert(31);    
    tree.insert(29);
    tree.insert(20);
}

int main()
{
    BinarySearchTree<int> tree;

    constructTree(tree);

    cout << "inorder: " << endl;
    tree.inorder();
    cout << endl;
    tree.iterativePreorder();
    cout << endl;

    cout << "preorder: " << endl;
    tree.preorder();
    cout << endl;    
    tree.iterativePreorder();
    cout << endl;

    cout << "postorder: " << endl; 
    tree.postorder();
    cout << endl;     
    tree.iterativePostorder();
    cout << endl;         

    cout << "breadthFirst: "; 
    tree.breadthFirst();
    cout << endl;
} 
