#include "Sorting.hpp"
#include <vector>
#include <string>

template <typename T>
void print(const std::vector<T>& v) {
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}


int main() {
    std::vector<std::string> strings {"xyz", "abc", "re", "the", "start", "hash", "graph", "dog", "cat"};
    std::vector<int> ints {43, 2, -2, 94, 934};

    Sorting::mergeSort(strings);
    Sorting::mergeSort(ints);

    print(ints);
    //std::cout << strings[5] << strings[4] << std::endl;
    std::cout << Sorting::binarySearch(ints, -2) << std::endl;

    return 0;
}