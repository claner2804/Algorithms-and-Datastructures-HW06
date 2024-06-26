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
    // Initialisierung des Index i (O(1))
    for (size_t i = 0; i < arr.size(); ++i) {
        // Vergleich des aktuellen Elements mit dem Ziel (O(1) pro Vergleich)
        if (arr[i] == target) {
            return i; // Element gefunden (O(1))
        }
    }
    return -1; // Element nicht gefunden (O(1))
    // Zeitkomplexität vor dem Kürzen:
    // Best-Case: 1 Vergleich -> O(1)
    // Average-Case: n/2 Vergleiche -> O(n/2)
    // Worst-Case: n Vergleiche -> O(n)
    // Nach dem Kürzen:
    // Best-Case: O(1)
    // Average-Case: O(n)
    // Worst-Case: O(n)
    // Raumkomplexität: O(1)
}


