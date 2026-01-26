#ifndef SLLIST_H
#define SLLIST_H

#include "SLList.hpp"


class SLList {
public:
    //No-argcontructor
    SLList();

    //The copy constructor
    SLList(const SLList& other); //TODO

    //Assignment operator
    SLList& operator=(const SLList& other); //TODO

    //The destructor
    ~SLList();

    unsigned size() const; //Returns the size of the list
    bool empty() const; //Returns true if list is empty
    void push_front(int val); //Insert the new node at the beginning
    void print() const; //print list
    //TODO
    void push_back(int val); //inesrt new node at the end
    void pop_front(); //remove the first element
    void clear(); //Clear the list

    //TODO pop_back, remove the last element
private:
    SLLNode* head;
    SLLNode* tail;
    unsigned list_size;
};

#endif