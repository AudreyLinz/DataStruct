#include "minHeap.hpp"

template<typename T>
void minHeap<T>::insert(const T& val){
    data.push_back(val);
    percolateUp();
}

template<typename T>
void minHeap<T>::print() const{
    for(const T& el : data){
        std::cout << el << std::endl;
    }
}

template<typename T>
void minHeap<T>::percolateUp(){
    int child_idx = data.size() - 1;
    int parent_idx = (child_idx - 1)/2;
    while(child_idx>0 && data[child_idx]<data[parent_idx]){
        std::swap(data[child_idx], data[parent_idx]);
        child_idx = parent_idx;
        parent_idx = (child_idx - 1)/2;
    }
}