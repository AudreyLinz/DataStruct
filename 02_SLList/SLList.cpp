#include "SLList.hpp"
#include <iostream>

SLList::SLList() {
    head = nullptr;
    list_size = 0;
}

unsigned SLList::size() const{ //unsigned is always positive since size should be positive
    return list_size;
}

bool SLList::empty() const{
    return (size()==0);
}

void SLList::push_front(int val){
    //Add new node at beginning
    /*
    SLLNode* new_node = new SLLNode(val);
    new_node->next = head;
    head = new_node;
    */

    //alt way
    head = new SLLNode(val, head/*this old address*/);

    list_size++; //Increase list size
}
void SLList::push_back(int val){
    while(cur){
        if(empty()){
            head = new SLLNode(val);
        } else{
            cur = cur->next;
        }
    }
}

void SLList::print() const{
    std::cout <<"{";

    SLLNode* cur = head;
    while(cur){
        std::cout << cur->data;
        if(cur->next){
            std::cout <<"->";
        }
        cur = cur->next; //goes to next node
    }
    std::cout << "}\n";
}