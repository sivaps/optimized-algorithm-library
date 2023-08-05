#include "traveling_salesman.h"
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>

// Function to calculate the distance between two cities
double calculateDistance(const City& city1, const City& city2) {
    double xDiff = city1.x - city2.x;
    double yDiff = city1.y - city2.y;
    return std::sqrt(xDiff * xDiff + yDiff * yDiff);
}

// Function to generate all possible subsets of cities
std::vector<std::vector<int>> generateSubsets(int n) {
    std::vector<std::vector<int>> subsets;
    for (int mask = 1; mask < (1 << n); ++mask) {
        std::vector<int> subset;
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                subset.push_back(i);
            }
        }
        subsets.push_back(subset);
    }
    return subsets;
}

// Function to solve the Traveling Salesman Problem using the Held-Karp algorithm
double travelingSalesmanHeldKarp(const std::vector<City>& cities) {
    int n = cities.size();

    // Special case when there are no cities
    if (n == 0) return 0;

    std::vector<std::vector<double>> dp(1 << n, std::vector<double>(n, std::numeric_limits<double>::infinity()));
    dp[1][0] = 0; // Base case: Starting at the first city

    std::vector<std::vector<int>> parent(1 << n, std::vector<int>(n, -1));

    std::vector<std::vector<int>> subsets = generateSubsets(n);

    for (const auto& subset : subsets) {
        for (int i = 1; i < n; ++i) {
            if (std::find(subset.begin(), subset.end(), i) == subset.end()) {
                for (int j : subset) {
                    double cost = dp[(1 << i) | (1 << j)][j] + calculateDistance(cities[j], cities[i]);
                    if (cost < dp[(1 << i) | (1 << j)][i]) {
                        dp[(1 << i) | (1 << j)][i] = cost;
                        parent[(1 << i) | (1 << j)][i] = j;
                    }
                }
            }
        }
    }

    double minCost = std::numeric_limits<double>::infinity();
    for (int i = 1; i < n; ++i) {
        double cost = dp[(1 << n) - 1][i] + calculateDistance(cities[i], cities[0]);
        if (cost < minCost) {
            minCost = cost;
        }
    }

    return minCost;
}

// Big O Notation:
// - Time Complexity: O(2^n * n^2)
// - Space Complexity: O(2^n * n)
