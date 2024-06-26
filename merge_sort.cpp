//
// Created by Claudia Steiner on 26.06.24.
//
/*
Mergesort

Zeitkomplexität:
Best-Case: 𝑂(𝑛 log n)
Average-Case: 𝑂(𝑛 log n)
Worst-Case: 𝑂(𝑛 log n)

Raumkomplexität:
 O(n)

 */
#include <iostream>
#include <vector>

void merge(std::vector<int>& arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    std::vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(std::vector<int>& arr, int l, int r) {
    if (l >= r) return;
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
    // Zeitkomplexität vor dem Kürzen:
    // Best-Case: n log n
    // Average-Case: n log n
    // Worst-Case: n log n
    // Nach dem Kürzen:
    // Best-Case: O(n log n)
    // Average-Case: O(n log n)
    // Worst-Case: O(n log n)
    // Raumkomplexität vor dem Kürzen: O(n)
    // Raumkomplexität nach dem Kürzen: O(n)
}
