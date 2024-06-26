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
    for (size_t i = 1; i < arr.size(); ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
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

