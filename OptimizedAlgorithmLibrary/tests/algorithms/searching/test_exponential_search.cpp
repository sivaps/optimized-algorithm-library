#include "exponential_search.h"
#include <iostream>
#include <vector>

int main() {
    std::vector<int> arr = {3, 9, 10, 27, 38, 43, 82};
    int target = 38;

    int index = exponentialSearch(arr, target);

    if (index != -1)
        std::cout << "Element " << target << " found at index " << index << std::endl;
    else
        std::cout << "Element " << target << " not found in the array." << std::endl;

    return 0;
}
