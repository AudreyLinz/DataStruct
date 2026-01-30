#include "DLList.hpp"
#include <iostream>

template <typename T>
DLList<T>::DLList(){
    head = new DLLNode<T>; //sentinel head node
    tail = new DLLNode<T>; //sentinel tail node
    head->next = tail;
    tail->prev = head;
    list_size = 0;
}

template <typename T>
void DLList<T>::push_front(const T& val){
    head->next = new DLLNode<T>(val, head, head->next);
    head->next->next->prev = head->next;

    list_size++;
}

template <typename T>
void DLList<T>::print() const {
    DLLNode<T>* cur = head->next;

    while(cur != tail){
        std::cout << cur->data;
        if(cur->next != tail){
            std::cout << " -> ";
        }
        cur = cur->next;
    }
    std::cout << std::endl;
}

template <typename T>
void DLList::pop_back() {
    if (!empty()){
        DLLNode<T>* to_delete = tail->prev;
        tail->prev = to_delete->prev;
        tail->prev->next = tail;

        list_size--;
        delete to_delete;
    }
}