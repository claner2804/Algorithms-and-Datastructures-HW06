//
// Created by Claudia Steiner on 26.06.24.
//
/*
Bucket Sort

Zeitkomplexität:
Best-Case: O(n+k)
Average-Case: 𝑂(n+k)
Worst-Case: 𝑂(𝑛^2) wenn alle Elemente in einem Bucket sind

Raumkomplexität:
 O(n+k)
 */
#include <iostream>
#include <vector>
#include <algorithm>

void bucketSort(std::vector<float>& arr) {
    int n = arr.size();
    std::vector<float> b[n];

    for (int i = 0; i < n; i++) {
        int bi = n * arr[i];
        b[bi].push_back(arr[i]);
    }

    for (int i = 0; i < n; i++) {
        std::sort(b[i].begin(), b[i].end());
    }

    int index = 0;
    for (int i = 0; i < n; i++) {
        for (size_t j = 0; j < b[i].size(); j++) {
            arr[index++] = b[i][j];
        }
    }
    // Zeitkomplexität vor dem Kürzen:
    // Best-Case: n + k
    // Average-Case: n + k
    // Worst-Case: n^2
    // Nach dem Kürzen:
    // Best-Case: O(n + k)
    // Average-Case: O(n + k)
    // Worst-Case: O(n^2)
    // Raumkomplexität: O(n + k)
}
