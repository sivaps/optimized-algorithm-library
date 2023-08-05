#include <vector>

// Function to perform Interpolation Search
int interpolationSearch(const std::vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right && target >= arr[left] && target <= arr[right]) {
        if (left == right) {
            if (arr[left] == target)
                return left;
            return -1;
        }

        // Calculate the position for interpolation
        int pos = left + ((target - arr[left]) * (right - left)) / (arr[right] - arr[left]);

        if (arr[pos] == target)
            return pos;

        if (arr[pos] < target)
            left = pos + 1;
        else
            right = pos - 1;
    }

    return -1; // Element not found
}

// Big O Notation:
// - Time Complexity: O(log log n) for uniformly distributed data; O(n) for non-uniform data
// - Space Complexity: O(1)
