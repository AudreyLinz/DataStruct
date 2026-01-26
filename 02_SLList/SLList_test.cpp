#include "SLList.hpp"

int main(void){
    SLList list;
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    list.push_front(4);

    list.print();
    return 0;
}