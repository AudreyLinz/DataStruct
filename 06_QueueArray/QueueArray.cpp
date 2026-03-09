
#include "QueueArray.hpp"
#include <iostream>
#include <stdexcept>

template <typename T, int size>
QueueArray<T, size>::QueueArray() {
    queue_size = 0;
    front_idx = back_idx = 0;
}

template <typename T, int size>
bool QueueArray<T, size>::full() const {
    return (queue_size == size);
}

template <typename T, int size>
bool QueueArray<T, size>::empty() const {
    return (queue_size == 0);
}

template <typename T, int size>
void QueueArray<T, size>::enqueue(const T& val) {
    if (!full()) {
        data[back_idx] = val; // Set the last element with the value
        back_idx = (back_idx + 1) % size;
        queue_size++;
    }
}

template <typename T, int size>
void QueueArray<T, size>::print() const {
    std::cout << "[ ";
    if (!empty()) {
        int i = front_idx;
        while (i != back_idx) {
            std::cout << data[i];
            i = (i + 1) % size;
            if (i != back_idx) {
                std::cout << ", ";
            }
        }
    }
    std::cout << " ]\n";
}

template <typename T, int size>
const T& QueueArray<T, size>::dequeue() {
    if (empty()) {
        throw std::out_of_range("Empty queue!");
    }
    int old_front = front_idx;
    front_idx = (front_idx + 1) % size;
    queue_size--;
    return data[old_front];
}
