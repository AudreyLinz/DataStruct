#ifndef SLLNODE_H
#define SLLNODE_H

template <typename T>
class SLLNode {
public:
    SLLNode(const T& d=T(), SLLNode<T> *n = nullptr) {
        data = d;
        next = n;
    }

    int data;
    SLLNode<T> *next; // pointer to the next node
};


#endif
