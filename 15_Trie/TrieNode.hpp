//Inclusion guard

#define ALPHABET_SIZE 26

class TrieNode{
public:
    TrieNode() : end_of_word(false){
        //initialize all childs with nullptr
    }

    TrieNode* children(ALPHABET_SIZE);
    bool end_of_word;
};