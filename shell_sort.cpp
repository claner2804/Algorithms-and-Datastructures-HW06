//
// Created by Claudia Steiner on 26.06.24.
//
#include <iostream>
#include <vector>

// Funktion zur Durchführung des Shell Sort
void shellSort(std::vector<int>& arr) {
    int n = arr.size();

    // Initialisierung der Lückenfolge
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // Zeitkomplexität: O(log n) für die äußere Schleife

        // Sortiere die Subarrays, die durch die aktuelle Lücke getrennt sind
        for (int i = gap; i < n; i += 1) {
            // Zeitkomplexität: O(n)
            int temp = arr[i]; // Das zu sortierende Element
            int j;

            // Verschiebe die Elemente des sortierten Teils
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap]; // Verschiebe Element
                // Zeitkomplexität: O(n) im Worst-Case
            }

            arr[j] = temp; // Füge das Element an der richtigen Position ein
        }
    }
}
