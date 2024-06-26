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
    for (size_t i = 0; i < arr.size() - 1; ++i) {
        size_t min_idx = i;
        for (size_t j = i + 1; j < arr.size(); ++j) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        std::swap(arr[i], arr[min_idx]);
    }
    // Zeitkomplexität vor dem Kürzen:
    // Best-Case: n(n-1)/2 Vergleiche
    // Average-Case: n(n-1)/2 Vergleiche
    // Worst-Case: n(n-1)/2 Vergleiche
    // Nach dem Kürzen:
    // Best-Case: O(n^2)
    // Average-Case: O(n^2)
    // Worst-Case: O(n^2)
    // Raumkomplexität: O(1)
}


