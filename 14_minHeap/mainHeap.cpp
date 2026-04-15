#include <iostream>
#include "minHeap.hpp"
#include "minHeap.cpp"
#include <cstdlib>
#include <vector>

template<typename T>
void heapSort(std::vector<T>& v){
    minHeap<T> heap(v);

    for(int i=0; i<v.size();i++){
        v[i] = heap.deleteMin();
    }
}

int main(void){
    minHeap<int> heap;
    std::vector<int> v;
    heap.insert(15);
    heap.insert(11);
    heap.insert(18);
    heap.insert(9);
    heap.insert(1);
    heap.print();


    /*
    for(int i = 0; i<10; i++){
        int num = rand()%1000;
        heap.insert(num);
        v.push_back(num);
    }

    minHeap<int> heap2(v);

    heap.print();
    std:: cout << "\n--------------\n";
    heap2.print();
    std::cout << "----------- \n";

    for(int i = 0; i < 10; i++){
        heap.deleteMin();
        heap.print();
        std::cout << "----------- \n";
    }
    */
    return 0;
}