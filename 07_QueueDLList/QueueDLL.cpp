
#include "QueueDLL.hpp"

template <typename T>
QueueDLL<T>::QueueDLL() {
    data = new DLList<T>;
}

template <typename T>
void QueueDLL<T>::enqueue(const T& val) {
    data->push_back(val);
}

template <typename T>
void QueueDLL<T>::print() const {
    data->print_backwards();
}
