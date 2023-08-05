#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <vector>
#include <utility>

using WeightedGraph = std::vector<std::vector<std::pair<int, int>>>;

// Function to perform Dijkstra's Shortest Path algorithm on a weighted graph
std::vector<int> dijkstra(const WeightedGraph& graph, int startVertex);

#endif // DIJKSTRAS_H
