# Set the minimum required version of CMake
cmake_minimum_required(VERSION 3.10)

# Set the project name
project(OptimizedAlgorithmLibrary)

# Set C++ standard to C++11
set(CMAKE_CXX_STANDARD 11)

# Add the source files for the Efficient Algorithm Library
set(SOURCE_FILES
    src/algorithms/sorting/merge_sort.cpp
    src/algorithms/sorting/quick_sort.cpp
    src/algorithms/sorting/heap_sort.cpp
    src/algorithms/sorting/tim_sort.cpp
    src/algorithms/sorting/counting_sort.cpp

    src/algorithms/searching/binary_search.cpp
    src/algorithms/searching/interpolation_search.cpp
    src/algorithms/searching/exponential_search.cpp
    src/algorithms/searching/jump_search.cpp
    src/algorithms/searching/fibonacci_search.cpp

    src/algorithms/graph/bfs.cpp
    src/algorithms/graph/dfs.cpp
    src/algorithms/graph/dijkstra.cpp
    src/algorithms/graph/prim.cpp
    src/algorithms/graph/kruskal.cpp

    src/algorithms/optimization/knapsack.cpp
    src/algorithms/optimization/traveling_salesman.cpp
    src/algorithms/optimization/genetic_algorithm.cpp

    src/data_structures/linked_list.cpp
    src/data_structures/binary_tree.cpp
    src/data_structures/hash_table.cpp
)

# Create a library from the source files
add_library(OptimizedAlgorithmLibrary ${SOURCE_FILES})

# Add the include directories for the library
target_include_directories(OptimizedAlgorithmLibrary PUBLIC
    include
)

# Add the executable for testing the library
add_executable(test_OptimizedAlgorithmLibrary
    tests/algorithms/sorting/test_merge_sort.cpp
    tests/algorithms/sorting/test_quick_sort.cpp
    tests/algorithms/sorting/test_heap_sort.cpp
    tests/algorithms/sorting/test_tim_sort.cpp
    tests/algorithms/sorting/test_counting_sort.cpp

    tests/algorithms/searching/test_binary_search.cpp
    tests/algorithms/searching/test_interpolation_search.cpp
    tests/algorithms/searching/test_exponential_search.cpp
    tests/algorithms/searching/test_jump_search.cpp
    tests/algorithms/searching/test_fibonacci_search.cpp

    tests/algorithms/graph/test_bfs.cpp
    tests/algorithms/graph/test_dfs.cpp
    tests/algorithms/graph/test_dijkstra.cpp
    tests/algorithms/graph/test_prim.cpp
    tests/algorithms/graph/test_kruskal.cpp

    tests/algorithms/optimization/test_knapsack.cpp
    tests/algorithms/optimization/test_traveling_salesman.cpp
    tests/algorithms/optimization/test_genetic_algorithm.cpp

    tests/data_structures/test_linked_list.cpp
    tests/data_structures/test_binary_tree.cpp
    tests/data_structures/test_hash_table.cpp
)

# Link the library with the test executable
target_link_libraries(test_OptimizedAlgorithmLibrary
    OptimizedAlgorithmLibrary
)
