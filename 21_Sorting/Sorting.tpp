#include "Sorting.hpp"
#include <iostream>
#include <vector>

template <typename T>
void Sorting::selectionSort(std::vector<T>& v) {
    int size = v.size()-1;
    
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        // TODO Find the minIndex
        for(int j = i + 1; j < size; j++){
            if(v[j] < v[minIndex]){
                minIndex = i;
            }
        }
        

        std::swap(v[i], v[minIndex]);
    }
}


template <typename T>
void Sorting::mergeSort(std::vector<T>& v) {
    mergeSort(v, 0, v.size() - 1);
}

template <typename T>
void Sorting::mergeSort(std::vector<T>& v, int left, int right) {
    if (left >= right) {
        return;
    }
    
    int mid = left + (right - left) / 2;
    
    mergeSort(v, left, mid);
    mergeSort(v, mid + 1, right);
    merge(v, left, mid, right);
}


template <typename T>
void Sorting::merge(std::vector<T>& v, int left, int mid, int right) {
    int size1 = mid - left + 1;
    int size2 = right - mid;

    std::vector<T> left_vector;
    std::vector<T> right_vector;

    for (int i = 0; i < size1; i++) {
        left_vector.push_back(v[left + i]); 
    }
    for (int i = 0; i < size2; i++) {
        right_vector.push_back(v[mid + 1 + i]); 
    }

    int i = 0, j = 0, k = left;

    // TODO Merge the vectors
    while(i < size1 && j < size2){
        if(left_vector[i] <= right_vector[j]){
            v[k] = left_vector[i];
            i++;
        } else {
            v[k] = right_vector[j];
            j++;
        }
        k++;
    }

    while(i < size1){
        v[k] = left_vector[i];
        i++;
        k++;
    }
    while(j < size2){
        v[k] = right_vector[j];
        j++;
        k++;
    }
}