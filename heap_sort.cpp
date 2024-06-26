//
// Created by Claudia Steiner on 26.06.24.
//
/*
Heap Sort

Zeitkomplexität:
Best-Case: 𝑂(𝑛 log n)
Average-Case: 𝑂(𝑛 log n)
Worst-Case: 𝑂(𝑛 log n)

Raumkomplexität:
 O(1)

 */
#include <iostream>
#include <vector>

void heapify(std::vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) largest = left;
    if (right < n && arr[right] > arr[largest]) largest = right;

    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
    // Zeitkomplexität für heapify: O(log n)
}

void heapSort(std::vector<int>& arr) {
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i >= 0; i--) {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
    // Zeitkomplexität vor dem Kürzen:
    // Best-Case: n log n
    // Average-Case: n log n
    // Worst-Case: n log n
    // Nach dem Kürzen:
    // Best-Case: O(n log n)
    // Average-Case: O(n log n)
    // Worst-Case: O(n log n)
    // Raumkomplexität: O(1)
}
