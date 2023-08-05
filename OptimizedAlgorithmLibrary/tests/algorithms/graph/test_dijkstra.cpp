#include "dijkstra.h"
#include <iostream>
#include <vector>

int main() {
    WeightedGraph graph = {
        {{1, 4}, {2, 2}},         // Neighbors and weights of vertex 0
        {{0, 4}, {2, 5}, {3, 2}}, // Neighbors and weights of vertex 1
        {{0, 2}, {1, 5}, {3, 1}}, // Neighbors and weights of vertex 2
        {{1, 2}, {2, 1}}          // Neighbors and weights of vertex 3
    };

    int startVertex = 0;
    std::vector<int> shortestDistances = dijkstras(graph, startVertex);

    std::cout << "Shortest Distances from vertex " << startVertex << " to all other vertices: ";
    for (int distance : shortestDistances) {
        std::cout << distance << " ";
    }
    std::cout << std::endl;

    return 0;
}
