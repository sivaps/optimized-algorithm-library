#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include <vector>

// Function to partition the array and return the pivot index
int partition(std::vector<int>& arr, int low, int high);

// Recursive function to perform Quick Sort
void quickSort(std::vector<int>& arr, int low, int high);

#endif // QUICK_SORT_H
