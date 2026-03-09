#ifndef DLLIST_H
#define DLLIST_H

#include "DLLNode.hpp"

class DLList {
public:
    // No-arg constructor
    DLList();

    // The copy constructor (TODO)
    //SLList(const SLList<T>& other);
    // Assignment operator (TODO)
    //SLList<T>& operator=(const SLList<T>& other);

    // The destructor
    //~SLList();

    //unsigned    size() const;  // Returns the size of the list
    //bool        empty() const; // Returns true if list is empty
    void        push_front(const T& val); // Insert the new node at the beginning
    void        print() const; // Print the list
    void        push_back(); // Insert the new node at the end

    //void        pop_front(); // Remove the first element (node)
    //void        clear();  // Clear the list

    // TODO
    //void        pop_back(); // Remove the last element (node)

private:
    DLLNode<T>* head; // The pointer to the first node
    DLLNode<T>* tail; // The pointer to the last node
    unsigned list_size;
};

#endif