
#ifndef QUEUEDLL_H
#define QUEUEDLL_H

#include "DLList.hpp"
#include "DLList.cpp"

template <typename T>
class QueueDLL {
public:
    QueueDLL();
    int length() const; // TODO
    bool empty() const;
    bool full() const;
    void print() const;
    oid clear(); // TODO
    void enqueue(const T& val);
    // Throws std::out_of_range exception
    const T& dequeue();
    const T& front(); // Return the first element in the queue TODO
private:
    DLList<T>* data;
};
#endif