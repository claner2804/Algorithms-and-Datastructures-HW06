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
    int pivot = arr[high]; // Pivot-Element
    int i = low - 1; // Index des kleineren Elements

    for (int j = low; j < high; j++) {
        // Vergleich des aktuellen Elements mit dem Pivot-Element
        if (arr[j] <= pivot) {
            i++;
            std::swap(arr[i], arr[j]); // Tausche Elemente
        }
    }
    std::swap(arr[i + 1], arr[high]); // Tausche das Pivot-Element an die richtige Stelle
    return i + 1;
}

void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // Aufteilen des Arrays
        // Rekursiver Aufruf für die linke und rechte Hälfte
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
    // Zeitkomplexität vor dem Kürzen:
    // Best-Case: 2T(n/2) + n
    // Worst-Case: T(n-1) + n
    // Average-Case: 2T(n/2) + n
    // Nach dem Kürzen:
    // Best-Case: O(n log n)
    // Worst-Case: O(n^2)
    // Average-Case: O(n log n)
    // Raumkomplexität vor dem Kürzen:
    // Best-Case: O(log n)
    // Worst-Case: O(n)
}

