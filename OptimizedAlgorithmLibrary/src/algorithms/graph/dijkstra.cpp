#include "dijkstra.h"
#include <vector>
#include <queue>
#include <limits>

// Function to perform Dijkstra's Shortest Path algorithm on a weighted graph
std::vector<int> dijkstras(const WeightedGraph& graph, int startVertex) {
    int numVertices = graph.size();
    std::vector<int> distances(numVertices, std::numeric_limits<int>::max());
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;

    distances[startVertex] = 0;
    pq.push({0, startVertex});

    while (!pq.empty()) {
        int currentDistance = pq.top().first;
        int currentVertex = pq.top().second;
        pq.pop();

        if (currentDistance > distances[currentVertex]) {
            continue;
        }

        for (const auto& edge : graph[currentVertex]) {
            int neighbor = edge.first;
            int weight = edge.second;
            int distance = currentDistance + weight;

            if (distance < distances[neighbor]) {
                distances[neighbor] = distance;
                pq.push({distance, neighbor});
            }
        }
    }

    return distances;
}

// Big O Notation:
// - Time Complexity: O(E * log(V)), where V is the number of vertices and E is the number of edges
// - Space Complexity: O(V + E), where V is the number of vertices and E is the number of edges
