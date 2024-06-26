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
    bool swapped;
    for (size_t i = 0; i < arr.size() - 1; ++i) {
        swapped = false;
        for (size_t j = 0; j < arr.size() - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
    // Zeitkomplexität vor dem Kürzen:
    // Best-Case: n-1 Vergleiche
    // Average-Case: n(n-1)/2 Vergleiche
    // Worst-Case: n(n-1)/2 Vergleiche
    // Nach dem Kürzen:
    // Best-Case: O(n)
    // Average-Case: O(n^2)
    // Worst-Case: O(n^2)
    // Raumkomplexität: O(1)
}
