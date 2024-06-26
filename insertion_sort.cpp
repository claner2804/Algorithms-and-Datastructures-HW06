//
// Created by Claudia Steiner on 26.06.24.
//
/*
Insertion Sort

Zeitkomplexität:
Best-Case: O(n) (Array ist bereits sortiert)
Average-Case: 𝑂(𝑛^2)
Worst-Case: 𝑂(𝑛^2)

Raumkomplexität:
 O(1)

 */
#include <iostream>
#include <vector>

void insertionSort(std::vector<int>& arr) {
    for (size_t i = 1; i < arr.size(); ++i) { // Äußere Schleife (O(n) Iterationen)
        int key = arr[i]; // Initialisierung von key (O(1))
        int j = i - 1; // Initialisierung von j (O(1))
        while (j >= 0 && arr[j] > key) { // Innere Schleife (O(n) Iterationen im Durchschnitt)
            arr[j + 1] = arr[j]; // Verschiebung des Elements (O(1))
            j--; // Dekrementierung von j (O(1))
        }
        arr[j + 1] = key; // Einfügen des Schlüssels (O(1))
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


