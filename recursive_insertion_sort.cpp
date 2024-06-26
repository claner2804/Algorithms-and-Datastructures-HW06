//
// Created by Claudia Steiner on 26.06.24.
//
/*
Recursive Insertion Sort

Zeitkomplexität:
Best-Case: O(n) (Array ist bereits sortiert)
Average-Case: 𝑂(𝑛^2)
Worst-Case: 𝑂(𝑛^2)

Raumkomplexität:
O(n) (durch den Rekursionsstapel)

 */
#include <iostream>
#include <vector>

void recursiveInsertionSort(std::vector<int>& arr, int n) {
    if (n <= 1) return; // Basisfall (O(1))
    recursiveInsertionSort(arr, n - 1); // Rekursiver Aufruf für n-1 Elemente (O(n-1))
    int key = arr[n - 1]; // Initialisierung von key (O(1))
    int j = n - 2; // Initialisierung von j (O(1))
    while (j >= 0 && arr[j] > key) { // Innere Schleife (O(n) Iterationen im Durchschnitt)
        arr[j + 1] = arr[j]; // Verschiebung des Elements (O(1))
        j--; // Dekrementierung von j (O(1))
    }
    arr[j + 1] = key; // Einfügen des Schlüssels (O(1))
    // Zeitkomplexität vor dem Kürzen:
    // Best-Case: n-1 Vergleiche -> O(n-1)
    // Average-Case: n(n-1)/2 Vergleiche -> O(n^2/2)
    // Worst-Case: n(n-1)/2 Vergleiche -> O(n^2/2)
    // Nach dem Kürzen:
    // Best-Case: O(n)
    // Average-Case: O(n^2)
    // Worst-Case: O(n^2)
    // Raumkomplexität vor dem Kürzen: O(n)
    // Raumkomplexität nach dem Kürzen: O(n)
}



