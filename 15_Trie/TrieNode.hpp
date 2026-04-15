#ifndef TRIE_NODE_HPP
#define TRIE_NODE_HPP

#define ALPHABET_SIZE 26

class TrieNode{
public:
    TrieNode() : end_of_word(false){
        //initialize all childs with nullptr
        for(int i = 0; i < ALPHABET_SIZE; i++){
            children[i] = nullptr;
        }
    }

    TrieNode* children[ALPHABET_SIZE];
    bool end_of_word;
};

#endif