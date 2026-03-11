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

    return 0;
}