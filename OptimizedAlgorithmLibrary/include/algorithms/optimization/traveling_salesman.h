#ifndef TRAVELING_SALESMAN_H
#define TRAVELING_SALESMAN_H

#include <vector>

// Structure to represent a city with x and y coordinates
struct City {
    double x;
    double y;
};

// Function to solve the Traveling Salesman Problem using the Held-Karp algorithm
double travelingSalesmanHeldKarp(const std::vector<City>& cities);

#endif // TRAVELING_SALESMAN_H
