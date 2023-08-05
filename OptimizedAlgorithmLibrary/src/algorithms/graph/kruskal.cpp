#include "kruskal.h"
#include <vector>
#include <algorithm>

// Function to find the parent of a vertex in a disjoint-set data structure
int findParent(int vertex, std::vector<int>& parent) {
    if (parent[vertex] == vertex)
        return vertex;
    return parent[vertex] = findParent(parent[vertex], parent);
}

// Function to perform Kruskal's Minimum Spanning Tree algorithm
std::vector<Edge> kruskal(const WeightedGraph& graph) {
    int numVertices = graph.size();
    std::vector<int> parent(numVertices);
    std::vector<Edge> mst;
    std::vector<Edge> edges;

    for (int i = 0; i < numVertices; ++i) {
        parent[i] = i;
        for (const auto& edge : graph[i]) {
            edges.push_back(Edge(i, edge.first, edge.second));
        }
    }

    std::sort(edges.begin(), edges.end());

    for (const auto& edge : edges) {
        int parentSrc = findParent(edge.src, parent);
        int parentDest = findParent(edge.dest, parent);

        if (parentSrc != parentDest) {
            mst.push_back(edge);
            parent[parentSrc] = parentDest;
        }
    }

    return mst;
}

// Big O Notation:
// - Time Complexity: O(E * log(E) + E * log(V)), where V is the number of vertices and E is the number of edges
// - Space Complexity: O(V + E), where V is the number of vertices and E is the number of edges
