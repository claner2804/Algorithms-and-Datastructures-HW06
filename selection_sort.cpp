//
// Created by Claudia Steiner on 26.06.24.
//
/*
Selection Sort

Zeitkomplexität:
Best-Case: 𝑂(𝑛^2)
Average-Case: 𝑂(𝑛^2)
Worst-Case: 𝑂(𝑛^2)

Raumkomplexität:
 O(1)

 */
#include <iostream>
#include <vector>

void selectionSort(std::vector<int>& arr) {
    for (size_t i = 0; i < arr.size() - 1; ++i) { // Äußere Schleife (O(n) Iterationen)
        size_t min_idx = i; // Initialisierung von min_idx (O(1))
        for (size_t j = i + 1; j < arr.size(); ++j) { // Innere Schleife (O(n) Iterationen im Durchschnitt)
            if (arr[j] < arr[min_idx]) { // Vergleich der Elemente (O(1) pro Vergleich)
                min_idx = j; // Aktualisierung von min_idx (O(1))
            }
        }
        std::swap(arr[i], arr[min_idx]); // Tausch der Elemente (O(1) pro Tausch)
    }
    // Zeitkomplexität vor dem Kürzen:
    // Best-Case, Average-Case, Worst-Case: n(n-1)/2 Vergleiche -> O(n^2/2)
    // Nach dem Kürzen:
    // Best-Case: O(n^2)
    // Average-Case: O(n^2)
    // Worst-Case: O(n^2)
    // Raumkomplexität: O(1)
}



