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
    if (n <= 1) return;
    recursiveInsertionSort(arr, n - 1);
    int key = arr[n - 1];
    int j = n - 2;
    while (j >= 0 && arr[j] > key) {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = key;
    // Zeitkomplexität vor dem Kürzen:
    // Best-Case: n-1 Vergleiche
    // Average-Case: n(n-1)/2 Vergleiche
    // Worst-Case: n(n-1)/2 Vergleiche
    // Nach dem Kürzen:
    // Best-Case: O(n)
    // Average-Case: O(n^2)
    // Worst-Case: O(n^2)
    // Raumkomplexität vor dem Kürzen: O(n)
    // Raumkomplexität nach dem Kürzen: O(n)
}


