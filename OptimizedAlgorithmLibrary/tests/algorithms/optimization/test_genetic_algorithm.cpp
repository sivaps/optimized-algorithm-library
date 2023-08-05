#include "genetic_algorithm.h"
#include <iostream>
#include <vector>

int main() {
    std::vector<int> weights = {10, 20, 30};
    std::vector<int> values = {60, 100, 120};
    int knapsackCapacity = 50;
    int populationSize = 100;
    int numGenerations = 100;
    double crossoverRate = 0.8;
    double mutationRate = 0.1;

    std::vector<bool> solution = knapsackGeneticAlgorithm(weights, values, knapsackCapacity, populationSize, numGenerations, crossoverRate, mutationRate);

    std::cout << "Selected Items: ";
    for (size_t i = 0; i < solution.size(); ++i) {
        if (solution[i])
            std::cout << "Item " << i << " ";
    }
    std::cout << std::endl;

    return 0;
}
