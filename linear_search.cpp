//
// Created by Claudia Steiner on 26.06.24.
//
/*
Linear Search

Zeitkomplexität:
Best-Case: O(1) (Das Element ist das erste im Array)
Average-Case: 𝑂(𝑛)
Worst-Case: 𝑂(𝑛) (Das Element ist das letzte oder nicht vorhanden)

Raumkomplexität:
 O(1)

 */
#include <iostream>
#include <vector>

int linearSearch(const std::vector<int>& arr, int target) {
    for (size_t i = 0; i < arr.size(); ++i) {
        if (arr[i] == target) {
            return i; // Element gefunden
        }
    }
    return -1; // Element nicht gefunden
    // Zeitkomplexität vor dem Kürzen:
    // Best-Case: 1 Vergleich
    // Average-Case: n/2 Vergleiche
    // Worst-Case: n Vergleiche
    // Nach dem Kürzen:
    // Best-Case: O(1)
    // Average-Case: O(n)
    // Worst-Case: O(n)
    // Raumkomplexität: O(1)
}

