#include "dfs.h"
#include <iostream>

int main() {
    Graph graph = {
        {1, 2},     // Neighbors of vertex 0
        {0, 2, 3},  // Neighbors of vertex 1
        {0, 1, 3},  // Neighbors of vertex 2
        {1, 2}      // Neighbors of vertex 3
    };

    int startVertex = 0;
    std::vector<int> traversalOrder = dfs(graph, startVertex);

    std::cout << "DFS Traversal Order starting from vertex " << startVertex << ": ";
    for (int vertex : traversalOrder) {
        std::cout << vertex << " ";
    }
    std::cout << std::endl;

    return 0;
}
