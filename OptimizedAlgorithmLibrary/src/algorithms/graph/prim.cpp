#include "prim.h"
#include <vector>
#include <queue>
#include <limits>

// Function to perform Prim's Minimum Spanning Tree algorithm
std::vector<Edge> prim(const WeightedGraph& graph, int startVertex) {
    int numVertices = graph.size();
    std::vector<bool> visited(numVertices, false);
    std::priority_queue<Edge, std::vector<Edge>, std::greater<Edge>> pq;
    std::vector<Edge> mst;

    visited[startVertex] = true;

    for (const auto& edge : graph[startVertex]) {
        pq.push(Edge(startVertex, edge.first, edge.second));
    }

    while (!pq.empty()) {
        Edge currentEdge = pq.top();
        pq.pop();

        if (visited[currentEdge.dest]) {
            continue;
        }

        visited[currentEdge.dest] = true;
        mst.push_back(currentEdge);

        for (const auto& edge : graph[currentEdge.dest]) {
            if (!visited[edge.first]) {
                pq.push(Edge(currentEdge.dest, edge.first, edge.second));
            }
        }
    }

    return mst;
}
