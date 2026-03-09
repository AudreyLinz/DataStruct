#include "BST.hpp"
#include "BST.cpp"

#include <iostream>
#include <string>

int main(void) {
    BST<int> tree;
    tree.insert(20);
    tree.insert(1);
    tree.insert(23);
    tree.insert(22);
    tree.insert(24);
    tree.insert(26);
    tree.insert(27);
    tree.insert(28);
    tree.insert(29);
    tree.insert(19);
    tree.insert(12);

    tree.print();
    
    std::cout << "QUIZ ACCESS CODE: ";
    std::cout << tree.getBalance(tree.search(23));
    std::cout << tree.getHeight(tree.search(20));    
    tree.balance();
    std::cout << tree.getBalance(tree.search(23));
    std::cout << tree.getHeight(tree.search(20));
    std::cout << std::endl;
    
    tree.print();

    return 0;
}