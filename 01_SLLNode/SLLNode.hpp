#ifndef SLLNODE_H
#define SLLNODE_H

class SLLNode {
public:
    SLLNode(int d=0, SLLNode *n = nullptr){
        data = d;
        next = n;
    } //constructor
    int data;
    SLLNode *next; //pointer to the next node

};

#endif