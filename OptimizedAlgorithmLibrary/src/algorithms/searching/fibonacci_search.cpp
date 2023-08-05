#include <vector>
#include <algorithm>

// Function to find the smallest Fibonacci number greater than or equal to n
int findFibonacci(int n) {
    int a = 0, b = 1, c = a + b;
    while (c < n) {
        a = b;
        b = c;
        c = a + b;
    }
    return b;
}

// Function to perform Fibonacci Search
int fibonacciSearch(const std::vector<int>& arr, int target) {
    int n = arr.size();
    int fibM = 0;
    int fibMminus2 = 0;
    int fibMminus1 = 1;

    // Find the smallest Fibonacci number greater than or equal to n
    while (fibM < n) {
        fibM = fibMminus1 + fibMminus2;
        fibMminus2 = fibMminus1;
        fibMminus1 = fibM;
    }

    int offset = -1;

    while (fibM > 1) {
        int i = std::min(offset + fibMminus2, n - 1);

        if (arr[i] < target) {
            fibM = fibMminus1;
            fibMminus1 = fibMminus2;
            fibMminus2 = fibM - fibMminus1;
            offset = i;
        } else if (arr[i] > target) {
            fibM = fibMminus2;
            fibMminus1 = fibMminus1 - fibMminus2;
            fibMminus2 = fibM - fibMminus1;
        } else {
            return i; // Element found
        }
    }

    if (fibMminus1 && arr[offset + 1] == target)
        return offset + 1; // Element found

    return -1; // Element not found
}

// Big O Notation:
// - Time Complexity: O(log n)
// - Space Complexity: O(1)
