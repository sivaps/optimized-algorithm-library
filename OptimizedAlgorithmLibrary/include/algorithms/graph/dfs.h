#ifndef DFS_H
#define DFS_H

#include <vector>

using Graph = std::vector<std::vector<int>>;

// Function to perform Depth-First Search on a graph
std::vector<int> dfs(const Graph& graph, int startVertex);

#endif // DFS_H
