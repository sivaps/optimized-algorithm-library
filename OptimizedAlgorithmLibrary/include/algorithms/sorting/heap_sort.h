#ifndef HEAP_SORT_H
#define HEAP_SORT_H

#include <vector>

// Helper function to heapify a subtree rooted at index i
void heapify(std::vector<int>& arr, int n, int i);

// Function to perform Heap Sort
void heapSort(std::vector<int>& arr);

#endif // HEAP_SORT_H
