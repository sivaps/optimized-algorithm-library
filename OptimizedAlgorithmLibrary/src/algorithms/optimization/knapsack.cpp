#include "knapsack.h"

// Function to solve the 0/1 Knapsack problem using Dynamic Programming
int knapsackDP(int knapsackCapacity, const std::vector<int>& weights, const std::vector<int>& values) {
    int n = weights.size();
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(knapsackCapacity + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= knapsackCapacity; ++w) {
            if (weights[i - 1] <= w)
                dp[i][w] = std::max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    return dp[n][knapsackCapacity];
}

// Big O Notation:
// - Time Complexity: O(n * knapsackCapacity)
// - Space Complexity: O(n * knapsackCapacity)
