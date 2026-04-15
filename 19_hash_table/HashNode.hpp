#ifndef HASHNODE_HPP
#define HASHNODE_HPP

template<typename K, typename V>
class HashNode{
public:
    HashNode(const K& key, const V& value): key(key), value(value) {
        
    }

    K key;
    V value;
private:

};

#endif