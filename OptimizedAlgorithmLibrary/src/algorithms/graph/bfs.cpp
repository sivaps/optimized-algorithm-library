#include "bfs.h"
#include <queue>
#include <vector>

// Function to perform Breadth-First Search on a graph
std::vector<int> bfs(const Graph& graph, int startVertex) {
    int numVertices = graph.size();
    std::vector<bool> visited(numVertices, false);
    std::vector<int> traversalOrder;
    std::queue<int> q;

    visited[startVertex] = true;
    q.push(startVertex);

    while (!q.empty()) {
        int currentVertex = q.front();
        q.pop();
        traversalOrder.push_back(currentVertex);

        for (int neighbor : graph[currentVertex]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

    return traversalOrder;
}

// Big O Notation:
// - Time Complexity: O(V + E), where V is the number of vertices and E is the number of edges
// - Space Complexity: O(V), where V is the number of vertices
