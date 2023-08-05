#ifndef KRUSKAL_H
#define KRUSKAL_H

#include <vector>
#include <utility>

using WeightedGraph = std::vector<std::vector<std::pair<int, int>>>;

// Helper structure to represent an edge with weight
struct Edge {
    int src;
    int dest;
    int weight;

    Edge(int s, int d, int w) : src(s), dest(d), weight(w) {}

    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

// Function to perform Kruskal's Minimum Spanning Tree algorithm
std::vector<Edge> kruskal(const WeightedGraph& graph);

#endif // KRUSKAL_H
