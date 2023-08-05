#include <vector>

// Function to perform Exponential Search
int exponentialSearch(const std::vector<int>& arr, int target) {
    int n = arr.size();

    // If the target is present at the first position
    if (arr[0] == target)
        return 0;

    // Find the range for binary search
    int i = 1;
    while (i < n && arr[i] <= target)
        i *= 2;

    // Perform binary search on the identified range
    int left = i / 2;
    int right = std::min(i, n - 1);

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1; // Element not found
}

// Big O Notation:
// - Time Complexity: O(log n)
// - Space Complexity: O(1)
