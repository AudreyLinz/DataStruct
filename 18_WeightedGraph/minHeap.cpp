#include "minHeap.hpp"
#include <iostream>
#include <algorithm> // for std::swap
#include <stdexcept> // for std::logic_error

template<typename T>
minHeap<T>::minHeap(){

}

template<typename T>
minHeap<T>::minHeap(const std::vector<T>& v) : data(v) {
    heapify();
}

template<typename T>
void minHeap<T>::insert(const T& val){
    data.push_back(val);
    percolateUp();
}

template<typename T>
void minHeap<T>::print() const{
    int cur_level = 0;
    int new_level = 1;

    for(int i = 0; i<data.size(); i++){
        std::cout << data[i] << " ";
        cur_level++;

        if(cur_level == new_level){
            std::cout << std::endl;
            new_level *= 2;
            cur_level = 0;
        }
    }
    std::cout << std::endl;
    std::cout << "---------" << std::endl;
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

template<typename T>
int minHeap<T>::getLeftKidIndex(int i){
    return i * 2 + 1;
}

template<typename T>
int minHeap<T>::getRightKidIndex(int i){
    return i * 2 + 2;
}

template<typename T>
int minHeap<T>::getParentIndex(int i){
    return (i - 1) / 2 ;
}

template<typename T>
int minHeap<T>::getLastWithKidsIndex(){
    return data.size() / 2 - 1;
}

template<typename T>
T minHeap<T>::deleteMin(){
    if(data.empty()){
        throw std::logic_error("deleteMin: empty heap");
    }
    T res = data[0];
    data[0] = data[data.size() - 1]; //set the last element as the root
    data.pop_back(); //remove the last element

    percolateDown();
    return res;
}

template<typename T>
void minHeap<T>::percolateDown(int i){
    int index = i;
    int size = data.size();

    while(getLeftKidIndex(index) < size){
        int left = getLeftKidIndex(index);
        int right = getRightKidIndex(index);

        int smallest = left;
        //Has 2 kids
        if(right < size && data[right] < data[left]){
            smallest = right;
        }
        if(data[index] < data[smallest]){
            break;
        }
        std::swap(data[index], data[smallest]);
        index = smallest;
    }
}

template<typename T>
void minHeap<T>::heapify(){
    for(int i=getLastWithKidsIndex(); i>=0; i--){
        percolateDown(i);
    }
}