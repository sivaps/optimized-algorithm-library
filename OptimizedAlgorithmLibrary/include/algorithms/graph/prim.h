#ifndef PRIM_H
#define PRIM_H

#include <vector>
#include <utility>

using WeightedGraph = std::vector<std::vector<std::pair<int, int>>>;

// Helper structure to represent an edge with weight
struct Edge {
    int src;
    int dest;
    int weight;

    Edge(int s, int d, int w) : src(s), dest(d), weight(w) {}

    bool operator>(const Edge& other) const {
        return weight > other.weight;
    }
};

// Function to perform Prim's Minimum Spanning Tree algorithm
std::vector<Edge> prim(const WeightedGraph& graph, int startVertex);

#endif // PRIM_H
