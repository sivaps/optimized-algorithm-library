#include <vector>
#include <algorithm>

// Function to perform Counting Sort
void countingSort(std::vector<int>& arr) {
    if (arr.empty())
        return;

    int maxElement = *std::max_element(arr.begin(), arr.end());
    int minElement = *std::min_element(arr.begin(), arr.end());

    int range = maxElement - minElement + 1;
    std::vector<int> count(range, 0);

    for (int num : arr)
        count[num - minElement]++;

    for (int i = 1; i < range; i++)
        count[i] += count[i - 1];

    std::vector<int> output(arr.size());

    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[arr[i] - minElement] - 1] = arr[i];
        count[arr[i] - minElement]--;
    }

    for (int i = 0; i < arr.size(); i++)
        arr[i] = output[i];
}

// Big O Notation:
// - Time Complexity: O(n + k), where n is the number of elements and k is the range of the input
// - Space Complexity: O(n + k)
