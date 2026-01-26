#ifndef SLLIST_H
#define SLLIST_H

#include "SLList.hpp"

class SLList {
public:
    //No-argcontructor
    SLList();

    unsigned size() const; //Returns the size of the list
    bool empty() const; //Returns true if list is empty
    void push_front(int val); //Insert the new node at the beginning
    void print() const; //print list
    //TODO
    void push_back(int val); //inesrt new node at the end
private:
    SLLNode* head;
    unsigned list_size;
};

#endif