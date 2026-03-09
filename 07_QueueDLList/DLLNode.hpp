#ifndef DLLNODE_H
#define DLLNODE_H

template <typename T>
class DLLNode {
public:
    DLLNode(const T& d = T(), DLLNode<T>* p = nullptr, DLLNode<T>* n = nullptr) {
        data = d;
        prev = p;
        next = n;
    }

    int data;
    DLLNode<T>* next; // pointer to the next node
    DLLNode<T>* prev; //pointer to the prev node
};


#endif
