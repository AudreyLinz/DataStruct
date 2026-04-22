#ifndef SORTING_HPP
#define SORTING_HPP
#include <vector>


class Sorting {
public:
    template <typename T>
    static void selectionSort(std::vector<T>& v);

    template <typename T>
    static void mergeSort(std::vector<T>& v);

private:
    template <typename T>
    static void mergeSort(std::vector<T>& v, int left, int right);
    template <typename T>
    static void merge(std::vector<T>& v, int left, int mid, int right);
};


#include "Sorting.tpp"

#endif