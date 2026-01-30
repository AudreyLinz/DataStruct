#include "SLList.hpp"
#include "SLList.cpp"
#include <string>

void test(SLList list) {
    SLList l2;
    l2 = list;
    l2.print();
}


int main(void) {
    SLList<std::string> list;
    list.push_front("abc");
    list.push_front("edf");
    list.push_front("123");
    list.push_front("hello");

    list.print();

    return 0;
}
