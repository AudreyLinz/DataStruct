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
    std::vector<std::string> strings {"xyz", "abc", "the", "dog", "cat"};
    std::vector<int> ints {43, 2, -2, 94, 934};

    print(strings);
    print(ints);

    Sorting::mergeSort(strings);
    Sorting::mergeSort(ints);

    print(strings);
    print(ints);

    return 0;
}