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
    int n = arr.size(); // Initialisierung von n (O(1))
    std::vector<float> b[n]; // Erstellen von n Buckets (O(n))

    for (int i = 0; i < n; i++) { // Verteilung der Elemente auf die Buckets (O(n) Iterationen)
        int bi = n * arr[i]; // Berechnung des Bucket-Index (O(1))
        b[bi].push_back(arr[i]); // Einfügen des Elements in den Bucket (O(1))
    }

    for (int i = 0; i < n; i++) { // Sortieren jedes Buckets (O(n) Iterationen)
        std::sort(b[i].begin(), b[i].end()); // Aufruf von std::sort (O(k log k) pro Bucket im Durchschnitt)
    }

    int index = 0; // Initialisierung von index (O(1))
    for (int i = 0; i < n; i++) { // Zusammenfügen der Buckets (O(n) Iterationen)
        for (size_t j = 0; j < b[i].size(); j++) { // Iteration über die Elemente im Bucket (O(k) Iterationen pro Bucket im Durchschnitt)
            arr[index++] = b[i][j]; // Einfügen des Elements in das Array (O(1))
        }
    }
    // Zeitkomplexität vor dem Kürzen:
    // Best-Case: n + k log k
    // Average-Case: n + k log k
    // Worst-Case: n^2 (wenn alle Elemente in einem Bucket sind)
    // Nach dem Kürzen:
    // Best-Case: O(n + k log k)
    // Average-Case: O(n + k log k)
    // Worst-Case: O(n^2)
    // Raumkomplexität: O(n + k)
}

