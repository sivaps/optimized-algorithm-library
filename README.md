# OptimizedAlgorithmLibrary

OptimizedAlgorithmLibrary is a collection of optimized algorithms implemented in C++. This library provides various efficient algorithms designed to tackle a wide range of tasks with optimal performance.

## Table of Contents
1. [Introduction](#introduction)
2. [Algorithms](#algorithms)
3. [Usage](#usage)
4. [Installation](#installation)
5. [Contributing](#contributing)

## Introduction

OptimizedAlgorithmLibrary houses a rich collection of optimized algorithms that are essential tools for developers and researchers. Each algorithm is designed to maximize performance while adhering to industry best practices and code standards. Whether you need sorting, searching, graph algorithms, optimization techniques, or fundamental data structures, this library has you covered.

## Algorithms

OptimizedAlgorithmLibrary includes the following optimized algorithms:

### Sorting Algorithms
1. Merge Sort: Efficient divide-and-conquer sorting algorithm with a time complexity of O(n log n) in the worst case.
2. Quick Sort: Fast sorting algorithm with an average time complexity of O(n log n).
3. Heap Sort: In-place sorting algorithm with a time complexity of O(n log n) in all cases.
4. Tim Sort: A hybrid sorting algorithm derived from Merge Sort and Insertion Sort, optimized for real-world data.
5. Counting Sort: Non-comparative integer sorting algorithm with a time complexity of O(n + k), suitable for small range values.

### Searching Algorithms
6. Binary Search: Efficient search algorithm for sorted arrays with a time complexity of O(log n).
7. Interpolation Search: Improved search algorithm for uniformly distributed data with an average time complexity of O(log log n).
8. Exponential Search: A variant of Binary Search that finds the range where the target is located, then performs Binary Search within that range.
9. Jump Search: Efficient search algorithm that jumps ahead by fixed steps to find the target element in a sorted array.
10. Fibonacci Search: Search algorithm using Fibonacci numbers to divide the array into smaller segments for efficient search.

### Graph Algorithms
11. Breadth-First Search (BFS): Graph traversal algorithm that visits all vertices at the same level before moving to the next level.
12. Depth-First Search (DFS): Graph traversal algorithm that explores as far as possible along each branch before backtracking.
13. Dijkstra's Shortest Path: Algorithm to find the shortest path between nodes in a weighted graph using a priority queue.
14. Prim's Minimum Spanning Tree: Algorithm to find the minimum spanning tree in a connected, undirected graph using a priority queue.
15. Kruskal's Minimum Spanning Tree: Algorithm to find the minimum spanning tree in a connected, undirected graph using Disjoint-Set Data Structure.

### Optimization Algorithms
16. 0/1 Knapsack Problem: Dynamic programming algorithm to find the most valuable combination of items without exceeding a given weight.
17. Traveling Salesman Problem: Optimization problem to find the shortest possible route visiting all cities and returning to the starting city.
18. Genetic Algorithm: Optimization technique inspired by the process of natural selection, used for solving complex optimization problems.

### Fundamental Data Structures
19. Linked List: A linear data structure that stores elements in a non-contiguous manner.
20. Binary Tree: A hierarchical data structure where each node has at most two children.
21. Hash Table: A data structure that implements an associative array with fast data retrieval.

### Advanced Data Structures
22. Red-Black Tree: A balanced binary search tree with logarithmic height, ensuring efficient operations.
23. Trie: A tree-like data structure used for efficient retrieval of strings and their prefixes.

## Usage

To use OptimizedAlgorithmLibrary in your C++ project, follow these steps:

1. Clone the project
2. Navigate to the library directory:
   cd OptimizedAlgorithmLibrary
3. Include the desired algorithm in your C++ code:<br>
   #include "src/algorithms/sorting/merge_sort.h"<br>
   // Include other algorithm headers as needed<br><br>
   Create an instance of the algorithm:<br>
   MergeSort mergeSort;<br>
   // Replace MergeSort with the desired algorithm (e.g., QuickSort, BFS, Knapsack, etc.)<br><br>
   Call the appropriate methods to use the algorithm:<br>
   std::vector<int> data = {9, 3, 1, 7, 5, 6, 8, 2, 4};<br>
   mergeSort.sort(data);<br>
   // Replace mergeSort.sort with the corresponding method for the chosen algorithm<br>
   The data will now be processed based on the chosen algorithm.<br>


## Installation
OptimizedAlgorithmLibrary is a header-only library, so there is no need for explicit installation. Simply clone the repository and include the desired algorithm's header in your project.

## Contributing
Contributions to the OptimizedAlgorithmLibrary are welcome! If you have any bug fixes, optimizations, or additional algorithms to add, please create a pull request.

Before making contributions, please ensure that your changes adhere to the project's coding standards, are thoroughly tested, and well-documented.

