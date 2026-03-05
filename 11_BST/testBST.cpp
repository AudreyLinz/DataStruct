#include "BST.hpp"
#include "BST.cpp"

#include <iostream>
#include <string>

int main(void) {
    BST<double> tree;

    //20, 10, 30, 5, 15, 25, 35, 12, 18
    tree.insert(20);
    tree.insert(10);
    tree.insert(30);
    tree.insert(5);
    tree.insert(15);
    tree.insert(25);
    tree.insert(35);
    tree.insert(12);
    tree.insert(18);

    tree.print();
    /*
    tree.print();
    tree.rotateValRight(10);
    tree.print();
    tree.rotateValLeft(5);
    tree.print();
    */
    /*
    tree.print();
    tree.deleteNode(2);
    tree.deleteNode(3);

    tree.print();
    tree.deleteAll();
    tree.print();
    */


    return 0;
}


