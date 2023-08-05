#ifndef BFS_H
#define BFS_H

#include <vector>

using Graph = std::vector<std::vector<int>>;

// Function to perform Breadth-First Search on a graph
std::vector<int> bfs(const Graph& graph, int startVertex);

#endif // BFS_H
