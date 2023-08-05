#include <vector>
#include <algorithm>

const int RUN = 32;

// Function to perform Insertion Sort on small segments of the array
void insertionSort(std::vector<int>& arr, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

// Function to merge two sorted subarrays
void merge(std::vector<int>& arr, int left, int mid, int right) {
    int len1 = mid - left + 1;
    int len2 = right - mid;

    std::vector<int> leftArr(len1);
    std::vector<int> rightArr(len2);

    for (int i = 0; i < len1; i++)
        leftArr[i] = arr[left + i];

    for (int i = 0; i < len2; i++)
        rightArr[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;

    while (i < len1 && j < len2) {
        if (leftArr[i] <= rightArr[j])
            arr[k++] = leftArr[i++];
        else
            arr[k++] = rightArr[j++];
    }

    while (i < len1)
        arr[k++] = leftArr[i++];

    while (j < len2)
        arr[k++] = rightArr[j++];
}

// Function to perform Tim Sort
void timSort(std::vector<int>& arr) {
    int n = arr.size();

    // Sort individual subarrays of size RUN
    for (int i = 0; i < n; i += RUN)
        insertionSort(arr, i, std::min(i + RUN - 1, n - 1));

    // Merge subarrays to produce sorted arrays
    for (int size = RUN; size < n; size = 2 * size) {
        for (int left = 0; left < n; left += 2 * size) {
            int mid = left + size - 1;
            int right = std::min(left + 2 * size - 1, n - 1);
            merge(arr, left, mid, right);
        }
    }
}

// Big O Notation:
// - Time Complexity: O(n log n)
// - Space Complexity: O(n)
