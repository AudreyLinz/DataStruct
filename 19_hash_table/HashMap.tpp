#include "HashMap.hpp"
#include <iostream>

template<typename K, typename V>
HashMap<K, V>::HashMap(int size) : n(0){
    data.resize(size, nullptr);

    deleted = new HashNode<K, V>(K(), V());
}

template<typename K, typename V>
bool HashMap<K, V>::empty() const{
    return n == 0;
}

template<typename K, typename V>
bool HashMap<K, V>::full() const{
    return n == data.size();
}

template<typename K, typename V>
int HashMap<K, V>::hash(const K& key) const{
    return key%data.size();
}

template<typename K, typename V>
void HashMap<K, V>::insert(const K& key, const V& value){
    if(full()){
        return;
    }

    //find the hash
    int index = hash(key);

    while(data[index] && data[index] != deleted){
        index = (index + 1)%data.size(); //go to the next position
    }

    //Insert the node
    data[index] = new HashNode(key, value);
    n++;
}

template<typename K, typename V>
void HashMap<K, V>::print() const{
    for(int i = 0; i<data.size(); i++){
        std::cout << i << " ";
        if(data[i] == nullptr){
            std::cout << "nullptr\n";
        } else if(data[i] == deleted){
            std::cout << "deleted\n";
        } else {
            std::cout << "{" << data[i]->key << "; " << data[i]->value << " } \n";
        }
    }
}

template<typename K, typename V>
int HashMap<K, V>::searchIndex(const K& key) const {
    int index = hash(key);
    int start = index;

    while (data[index] != nullptr) {
        // If it's not a deleted node and keys match, we found it
        if (data[index] != deleted && data[index]->key == key) {
            return index;
        }
        index = (index + 1) % data.size();
        
        // Safety break if we loop back to start
        if (index == start) break;
    }
    return -1; // Not found
}

template<typename K, typename V>
const V& HashMap<K, V>::search(const K& key) const {
    int index = searchIndex(key);
    if (index == -1) {
        throw std::runtime_error("Key not found");
    }
    return data[index]->value;
}

template<typename K, typename V>
void HashMap<K, V>::remove(const K& key) {
    int index = searchIndex(key);
    if (index != -1) {
        delete data[index];   // Free memory
        data[index] = deleted; // Mark as deleted to preserve probe chain
        n--;
    }
}