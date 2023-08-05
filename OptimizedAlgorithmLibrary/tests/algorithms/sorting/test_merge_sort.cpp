#include "algorithms/sorting/merge_sort.h"
#include <iostream>
#include <vector>

int main() {
    std::vector<int> arr = {38, 27, 43, 3, 9, 82, 10};
    std::cout << "Original Array: ";
    for (int num : arr)
        std::cout << num << " ";

    mergeSort(arr, 0, arr.size() - 1);

    std::cout << "\nSorted Array: ";
    for (int num : arr)
        std::cout << num << " ";

    std::cout << std::endl;
    return 0;
}
