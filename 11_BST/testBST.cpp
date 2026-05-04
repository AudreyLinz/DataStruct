#include "BST.hpp"
#include "BST.cpp"

#include <iostream>
#include <string>

int main(void) {
    BST<int> tree;
    tree.insert(20);
    tree.insert(10);
    tree.insert(3);
    tree.insert(25);
    tree.insert(11);
    tree.preorder();
    tree.inorder();
    tree.postorder();

    tree.deleteAll();

    tree.insert(4);
    tree.insert(10);
    tree.insert(3);
    tree.insert(25);
    tree.insert(9);
    tree.preorder();
    tree.inorder();
    tree.postorder();

    tree.insert(30);
    tree.print();
    tree.balance();
    tree.print();

    tree.extractMax();

    return 0;
}