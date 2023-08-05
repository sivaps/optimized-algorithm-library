#include "knapsack.h"
#include <iostream>
#include <vector>

int main() {
    std::vector<int> weights = {10, 20, 30};
    std::vector<int> values = {60, 100, 120};
    int knapsackCapacity = 50;

    int maxTotalValue = knapsackDP(knapsackCapacity, weights, values);

    std::cout << "Maximum total value that can be achieved: " << maxTotalValue << std::endl;

    return 0;
}
