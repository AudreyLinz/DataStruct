#include "SLList.hpp"
#include <iostream>


SLList::SLList() {
    head = nullptr;
    tail = nullptr;
    list_size = 0;
}

SLList::~SLList(){
    clear();
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

    if(size() == 1 ){
        tail = head;
    }
}

void SLList::push_back(int val){
    if(empty()){
        push_front(val);
        return;
    }
    tail->next = new SLLNode(val); //add node to end
    tail = tail->next; //move tail

    list_size++;
}

void SLList::pop_front(){
    if(!empty()){
        SLLNode* old_head = head;
        head = head->next;

        delete old_head; //free the meemory

        list_size--;
        if(empty()){
            tail = head;
        }
    }
}

void SLList::clear(){
    while(!empty()){
        pop_front();
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