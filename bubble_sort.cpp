//
// Created by Claudia Steiner on 26.06.24.
//
/*
Bubble Sort

Zeitkomplexität:
Best-Case: O(n) (Array ist bereits sortiert)
Average-Case: 𝑂(𝑛^2)
Worst-Case: 𝑂(𝑛^2)

Raumkomplexität:
 O(1)

 */
#include <iostream>
#include <vector>

void bubbleSort(std::vector<int>& arr) {
    bool swapped; // Initialisierung von swapped (O(1))
    for (size_t i = 0; i < arr.size() - 1; ++i) { // Äußere Schleife (O(n) Iterationen)
        swapped = false; // Initialisierung von swapped für jede Iteration (O(1))
        for (size_t j = 0; j < arr.size() - i - 1; ++j) { // Innere Schleife (O(n) Iterationen im Durchschnitt)
            if (arr[j] > arr[j + 1]) { // Vergleich der Elemente (O(1) pro Vergleich)
                std::swap(arr[j], arr[j + 1]); // Tausch der Elemente (O(1) pro Tausch)
                swapped = true; // Aktualisierung von swapped (O(1))
            }
        }
        if (!swapped) break; // Überprüfung von swapped (O(1))
    }
    // Zeitkomplexität vor dem Kürzen:
    // Best-Case: n-1 Vergleiche -> O(n-1)
    // Average-Case: n(n-1)/2 Vergleiche -> O(n^2/2)
    // Worst-Case: n(n-1)/2 Vergleiche -> O(n^2/2)
    // Nach dem Kürzen:
    // Best-Case: O(n)
    // Average-Case: O(n^2)
    // Worst-Case: O(n^2)
    // Raumkomplexität: O(1)
}

