#include "genetic_algorithm.h"
#include <algorithm>
#include <ctime>
#include <cstdlib>

// Function to initialize a random population of chromosomes
std::vector<std::vector<bool>> initializePopulation(int populationSize, int chromosomeLength) {
    std::vector<std::vector<bool>> population;

    for (int i = 0; i < populationSize; ++i) {
        std::vector<bool> chromosome(chromosomeLength);
        for (int j = 0; j < chromosomeLength; ++j) {
            chromosome[j] = rand() % 2;
        }
        population.push_back(chromosome);
    }

    return population;
}

// Function to evaluate the fitness of each chromosome
std::vector<int> evaluateFitness(const std::vector<std::vector<bool>>& population, const std::vector<int>& weights, const std::vector<int>& values, int knapsackCapacity) {
    std::vector<int> fitnessValues;
    for (const auto& chromosome : population) {
        int totalWeight = 0;
        int totalValue = 0;
        for (size_t i = 0; i < chromosome.size(); ++i) {
            if (chromosome[i]) {
                totalWeight += weights[i];
                totalValue += values[i];
            }
        }
        if (totalWeight <= knapsackCapacity)
            fitnessValues.push_back(totalValue);
        else
            fitnessValues.push_back(0);
    }
    return fitnessValues;
}

// Function to select parent chromosomes for reproduction
std::pair<int, int> selection(const std::vector<int>& fitnessValues) {
    int totalFitness = 0;
    for (int fitness : fitnessValues)
        totalFitness += fitness;

    int r1 = rand() % totalFitness;
    int r2 = rand() % totalFitness;

    int sum = 0;
    int parent1 = -1;
    int parent2 = -1;

    for (size_t i = 0; i < fitnessValues.size(); ++i) {
        sum += fitnessValues[i];
        if (parent1 == -1 && sum >= r1)
            parent1 = i;
        if (parent2 == -1 && sum >= r2)
            parent2 = i;

        if (parent1 != -1 && parent2 != -1)
            break;
    }

    return std::make_pair(parent1, parent2);
}

// Function to perform crossover between parent chromosomes
std::vector<bool> crossover(const std::vector<bool>& parent1, const std::vector<bool>& parent2) {
    int length = parent1.size();
    int crossoverPoint = rand() % length;

    std::vector<bool> child(length);
    for (int i = 0; i < crossoverPoint; ++i)
        child[i] = parent1[i];

    for (int i = crossoverPoint; i < length; ++i)
        child[i] = parent2[i];

    return child;
}

// Function to perform mutation on a chromosome
void mutate(std::vector<bool>& chromosome, double mutationRate) {
    for (size_t i = 0; i < chromosome.size(); ++i) {
        double r = static_cast<double>(rand()) / RAND_MAX;
        if (r < mutationRate)
            chromosome[i] = !chromosome[i];
    }
}

// Function to perform the Genetic Algorithm for the 0/1 Knapsack problem
std::vector<bool> knapsackGeneticAlgorithm(const std::vector<int>& weights, const std::vector<int>& values, int knapsackCapacity, int populationSize, int numGenerations, double crossoverRate, double mutationRate) {
    srand(static_cast<unsigned>(time(0)));

    int chromosomeLength = weights.size();
    std::vector<std::vector<bool>> population = initializePopulation(populationSize, chromosomeLength);

    for (int generation = 0; generation < numGenerations; ++generation) {
        std::vector<int> fitnessValues = evaluateFitness(population, weights, values, knapsackCapacity);

        std::vector<std::vector<bool>> newPopulation;
        for (int i = 0; i < populationSize; ++i) {
            std::pair<int, int> parents = selection(fitnessValues);
            std::vector<bool> child;
            if (static_cast<double>(rand()) / RAND_MAX < crossoverRate) {
                child = crossover(population[parents.first], population[parents.second]);
            } else {
                child = population[parents.first];
            }

            mutate(child, mutationRate);
            newPopulation.push_back(child);
        }

        population = newPopulation;
    }

    std::vector<int> finalFitnessValues = evaluateFitness(population, weights, values, knapsackCapacity);
    int bestIndex = std::max_element(finalFitnessValues.begin(), finalFitnessValues.end()) - finalFitnessValues.begin();
    return population[bestIndex];
}

// Big O Notation:
// - Time Complexity: O(numGenerations * populationSize * chromosomeLength)
// - Space Complexity: O(populationSize * chromosomeLength)
