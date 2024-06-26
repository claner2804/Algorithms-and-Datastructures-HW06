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
    int largest = i; // Initialisierung von largest (O(1))
    int left = 2 * i + 1; // Berechnung des linken Kindes (O(1))
    int right = 2 * i + 2; // Berechnung des rechten Kindes (O(1))

    if (left < n && arr[left] > arr[largest]) largest = left; // Vergleich und Aktualisierung von largest (O(1))
    if (right < n && arr[right] > arr[largest]) largest = right; // Vergleich und Aktualisierung von largest (O(1))

    if (largest != i) { // Überprüfung, ob largest aktualisiert wurde (O(1))
        std::swap(arr[i], arr[largest]); // Tausch der Elemente (O(1))
        heapify(arr, n, largest); // Rekursiver Aufruf (O(log n))
    }
    // Zeitkomplexität für heapify: O(log n)
}

void heapSort(std::vector<int>& arr) {
    int n = arr.size(); // Initialisierung von n (O(1))

    for (int i = n / 2 - 1; i >= 0; i--) { // Aufbau des Heaps (O(n) Iterationen)
        heapify(arr, n, i); // Aufruf von heapify (O(log n) pro Aufruf)
    }

    for (int i = n - 1; i >= 0; i--) { // Extrahieren der Elemente (O(n) Iterationen)
        std::swap(arr[0], arr[i]); // Tausch der Elemente (O(1))
        heapify(arr, i, 0); // Aufruf von heapify (O(log n) pro Aufruf)
    }
    // Zeitkomplexität vor dem Kürzen:
    // Best-Case, Average-Case, Worst-Case: n log n
    // Nach dem Kürzen:
    // Best-Case: O(n log n)
    // Average-Case: O(n log n)
    // Worst-Case: O(n log n)
    // Raumkomplexität: O(1)
}

