#include "SLList.hpp"
#include <iostream>

template<typename T>
SLList<T>::SLList() {
    head = nullptr;
    tail = nullptr;
    list_size = 0;
}

template<typename T>
SLList<T>::~SLList() {
    clear();
}

template<typename T>
SLList<T>::SLList(const SLList& other) {
    head = nullptr;
    tail = nullptr;
    list_size = 0;

    SLLNode<T>* cur = other.head;
    while (cur != nullptr) {
        this->push_back(cur->data);
        cur = cur->next;
    }
}

template<typename T>
SLList& SLList<T>::operator=(const SLList& other) {
    if (this == &other) {
        return *this;
    }

    while (!empty()) {
        pop_back();
    }

    SLLNode<T>* cur = other.head;
    while (cur != nullptr) {
        this->push_back(cur->data);
        cur = cur->next;
    }

    return *this;
}

template<typename T>
unsigned SLList<T>::size() const {
    return list_size;
}

template<typename T>
bool SLList<T>::empty() const {
    return (size() == 0);
}

template<typename T>
void SLList<T>::push_front(int val) {
    head = new SLLNode<T>(val, head);

    // Increase the list size
    list_size++;

    if (size() == 1) {
        tail = head;
    }
}

template<typename T>
void SLList<T>::print() const {
    std::cout << "{ ";

    SLLNode<T>* cur = head;
    while (cur) {
        std::cout << cur->data;
        if (cur->next) {
            std::cout << " -> ";
        }
        cur = cur->next; // Goes to the next node
    }
    std::cout << " }\n";
}

template<typename T>
void SLList<T>::push_back(int val) {
    if (empty()) {
        push_front(val);
        return;
    }
    tail->next = new SLLNode<T>(val); // Add the node to the end
    tail = tail->next; // Move the tail

    list_size++;
}

template<typename T>
void SLList<T>::pop_front() {
    if (!empty()) {
        SLLNode<T>* old_head = head;
        head = head->next;

        delete old_head; // Free the memory

        list_size--;
        if (empty()) {
            tail = head;
        }
    }
}

template<typename T>
void SLList<T>::pop_back(){
    if(!empty()){
        if (head == tail) { //Only one node in the list
            delete head;
            head = nullptr;
            tail = nullptr;
        } else {
            SLLNode<T>* cur = head;
            while(cur->next!=tail) {
                cur = cur->next;
            }
            delete tail;
            tail=cur;
            tail->next = nullptr;
        }
        list_size--;
    }
}

template<typename T>
void SLList<T>::clear() {
    while (!empty()) {
        pop_front();
    }
}

template<typename T>
SLList& SLList<T>::operator=(const SLList<T>& other){
    clear();
    SLLNode<T>* cur = other.head;
    while(cur){
        push_back(cur->data);
        cur = cur-> next;
    }
    return *this;
}