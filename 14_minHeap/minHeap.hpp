#ifndef MIN_HEAP_HPP
#define MIN_HEAP_HPP

#include <vector>

template<typename T>
class minHeap {
public:
    void insert(const T& val);
    void print() const;
private:
    std::vector<T> data;

    void percolateUp();
};

#endif