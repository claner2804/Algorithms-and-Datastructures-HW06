//
// Created by Claudia Steiner on 26.06.24.
//
/*
Quick Sort

Zeitkomplexität:
Best-Case: O(n log n)
Average-Case: 𝑂(𝑛 log n)
Worst-Case: 𝑂(𝑛^2) (wenn das Pivot-Element immer das kleinste oder größte Element ist)

Raumkomplexität:
    O(log n) (durch den Rekursionsstapel)

 */
#include <iostream>
#include <vector>

int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // Wahl des Pivot-Elements (O(1))
    int i = low - 1; // Initialisierung von i (O(1))

    for (int j = low; j < high; j++) { // Schleife von low bis high (O(n) Iterationen)
        if (arr[j] <= pivot) { // Vergleich des aktuellen Elements mit dem Pivot-Element (O(1))
            i++; // Inkrementierung von i (O(1))
            std::swap(arr[i], arr[j]); // Tausch der Elemente (O(1))
        }
    }
    std::swap(arr[i + 1], arr[high]); // Tausch des Pivot-Elements an die richtige Stelle (O(1))
    return i + 1; // Rückgabe des Index des Pivot-Elements (O(1))
}

void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) { // Basisfall (O(1))
        int pi = partition(arr, low, high); // Aufteilen des Arrays (O(n))
        quickSort(arr, low, pi - 1); // Rekursiver Aufruf für die linke Hälfte (O(log n) Aufrufe im Durchschnitt)
        quickSort(arr, pi + 1, high); // Rekursiver Aufruf für die rechte Hälfte (O(log n) Aufrufe im Durchschnitt)
    }
    // Zeitkomplexität vor dem Kürzen:
    // Best-Case: n log n
    // Average-Case: n log n
    // Worst-Case: n^2
    // Nach dem Kürzen:
    // Best-Case: O(n log n)
    // Average-Case: O(n log n)
    // Worst-Case: O(n^2)
    // Raumkomplexität vor dem Kürzen: O(log n)
    // Raumkomplexität nach dem Kürzen: O(log n)
    // Worst-Case Raumkomplexität: O(n)
}

