#include "QueueDLL.hpp"
#include "QueueDLL.cpp"

int main(void) {
    QueueDLL<int> q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.print();
    
    return 0;
}
