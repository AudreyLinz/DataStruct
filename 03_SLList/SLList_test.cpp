#include "SLList.hpp"

int main(void){
    SLList list;
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    list.push_front(4);

    list.push_back(9);
    list.push_back(8);
    list.push_back(7);
    list.push_back(6);

    list.print();

    list.pop_front();
    list.pop_front();

    list.print();
    list.clear();
    
    return 0;
}