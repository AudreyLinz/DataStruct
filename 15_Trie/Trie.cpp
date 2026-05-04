#include "Trie.hpp"
#include <iostream>
#include <string>

Trie::Trie(){
    root = new TrieNode();
}

void Trie::insert(const std::string& s){
    TrieNode* cur = root;
    for(char c:s){
        if(!isalpha(c)){
            continue;
        }
        int i = tolower(c) - 'a';
        if(!cur->children[i]){
            cur->children[i] = new TrieNode();
        }
        cur = cur->children[i];
    }
    cur->end_of_word = true;
}

bool Trie::search(const std::string& s) const{
    TrieNode* cur = root;

    for(char c : s){
        int i = tolower(c) - 'a';
        if(!cur->children[i]){
            return false;
        }
        cur = cur->children[i];
    }

    return cur->end_of_word;
}

void Trie::print() const {
    std::string word;
    print(root, word);
}

void Trie::print(const TrieNode* node, std::string word) const {
    if (!node) return;

    if (node->end_of_word) {
        std::cout << word << std::endl;
    }

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (node->children[i]) {
            char c = 'a' + i;
            print(node->children[i], word + c);
        }
    }
}

bool Trie::startsWith(const std::string& prefix) const {
    TrieNode* cur = root;

    for (char c : prefix) {
        int i = tolower(c) - 'a';
        
        if (!cur->children[i]) {
            return false;
        }

        cur = cur->children[i];
    }

    return true;
}