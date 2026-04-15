#include "Trie.hpp"
#include <iostream>

int main(){
    Trie trie;

    trie.insert("abc");
    trie.insert("xyz");
    trie.insert("abcd");

    std::cout << trie.search("abc") << std::endl;
    std::cout << trie.search("abd") << std::endl;

    return 0;
}