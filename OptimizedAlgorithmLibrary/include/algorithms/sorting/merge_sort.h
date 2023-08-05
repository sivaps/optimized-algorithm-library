#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include <vector>

// Function to merge two sorted subarrays into a single sorted array
void merge(std::vector<int>& arr, int left, int mid, int right);

// Recursive function to perform Merge Sort
void mergeSort(std::vector<int>& arr, int left, int right);

#endif // MERGE_SORT_H
