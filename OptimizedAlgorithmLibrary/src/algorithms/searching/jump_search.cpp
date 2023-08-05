#include <vector>
#include <cmath>

// Function to perform Jump Search
int jumpSearch(const std::vector<int>& arr, int target) {
    int n = arr.size();
    int step = static_cast<int>(sqrt(n));
    int prev = 0;

    while (arr[std::min(step, n) - 1] < target) {
        prev = step;
        step += static_cast<int>(sqrt(n));
        if (prev >= n)
            return -1; // Element not found
    }

    while (arr[prev] < target) {
        prev++;

        if (prev == std::min(step, n))
            return -1; // Element not found
    }

    if (arr[prev] == target)
        return prev;

    return -1; // Element not found
}

// Big O Notation:
// - Time Complexity: O(sqrt(n))
// - Space Complexity: O(1)
