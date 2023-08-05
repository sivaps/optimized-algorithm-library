#include "traveling_salesman.h"
#include <iostream>
#include <vector>

int main() {
    std::vector<City> cities = {{0, 0}, {1, 2}, {2, 3}, {5, 1}};

    double minDistance = travelingSalesmanHeldKarp(cities);

    std::cout << "Minimum distance for Traveling Salesman Problem: " << minDistance << std::endl;

    return 0;
}
