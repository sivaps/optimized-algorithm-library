#ifndef GENETIC_ALGORITHM_H
#define GENETIC_ALGORITHM_H

#include <vector>

// Function to perform the Genetic Algorithm for the 0/1 Knapsack problem
std::vector<bool> knapsackGeneticAlgorithm(const std::vector<int>& weights, const std::vector<int>& values, int knapsackCapacity, int populationSize, int numGenerations, double crossoverRate, double mutationRate);

#endif // GENETIC_ALGORITHM_H
