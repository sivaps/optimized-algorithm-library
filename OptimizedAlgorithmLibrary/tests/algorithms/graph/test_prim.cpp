#include "prim.h"
#include <iostream>
#include <vector>

int main() {
    WeightedGraph graph = {
        {{1, 4}, {7, 8}},         // Neighbors and weights of vertex 0
        {{0, 4}, {2, 8}, {7, 11}}, // Neighbors and weights of vertex 1
        {{1, 8}, {3, 7}, {5, 4}, {8, 2}}, // Neighbors and weights of vertex 2
        {{2, 7}, {4, 9}, {5, 14}}, // Neighbors and weights of vertex 3
        {{3, 9}, {5, 10}},         // Neighbors and weights of vertex 4
        {{2, 4}, {3, 14}, {4, 10}, {6, 2}}, // Neighbors and weights of vertex 5
        {{5, 2}, {7, 1}, {8, 6}},  // Neighbors and weights of vertex 6
        {{0, 8}, {1, 11}, {6, 1}, {8, 7}}, // Neighbors and weights of vertex 7
        {{2, 2}, {6, 6}, {7, 7}}   // Neighbors and weights of vertex 8
    };

    int startVertex = 0;
    std::vector<Edge> mst = prim(graph, startVertex);

    int totalWeight = 0;
    std::cout << "Edges in the Minimum Spanning Tree:" << std::endl;
    for (const auto& edge : mst) {
        std::cout << edge.src << " - " << edge.dest << " (weight: " << edge.weight << ")" << std::endl;
        totalWeight += edge.weight;
    }

    std::cout << "Total weight of Minimum Spanning Tree: " << totalWeight << std::endl;

    return 0;
}
