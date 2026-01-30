#include "DLList.hpp"
#include "DLList.cpp"

int main(void){
    DLList<char> list;

    list.push_front('a');
    list.push_front('b');
    list.push_front('c');

    list.print();
    return 0;
}