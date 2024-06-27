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

 */#include <iostream>
#include <vector>

// Funktion zum Zusammenführen zweier sortierter Teilarrays
void merge(std::vector<int>& arr, int l, int m, int r) {
    int n1 = m - l + 1; // Berechnung der Größe des linken Subarrays (O(1))
    int n2 = r - m; // Berechnung der Größe des rechten Subarrays (O(1))
    std::vector<int> L(n1), R(n2); // Initialisierung der temporären Arrays (O(n1 + n2))

    // Kopieren der Daten in L und R
    for (int i = 0; i < n1; i++) {
        L[i] = arr[l + i]; // Kopieren der Daten in L (O(n1))
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j]; // Kopieren der Daten in R (O(n2))
    }

    int i = 0, j = 0, k = l; // Initialisierung der Indizes (O(1))

    // Mergen der temporären Arrays in arr
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Kopieren der restlichen Elemente von L, falls vorhanden
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Kopieren der restlichen Elemente von R, falls vorhanden
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Funktion zur Durchführung des Merge Sort
void mergeSort(std::vector<int>& arr, int l, int r) {
    if (l >= r) return; // Basisfall (O(1))

    int m = l + (r - l) / 2; // Berechnung der Mitte (O(1))

    // Rekursiver Aufruf für die linke Hälfte (O(log n) Aufrufe)
    mergeSort(arr, l, m);
    // Rekursiver Aufruf für die rechte Hälfte (O(log n) Aufrufe)
    mergeSort(arr, m + 1, r);

    // Mergen der sortierten Hälften (O(n))
    merge(arr, l, m, r);
}

// Zeitkomplexität vor dem Kürzen:
// Best-Case, Average-Case, Worst-Case: n log n

// Nach dem Kürzen:
// Best-Case: O(n log n)
// Average-Case: O(n log n)
// Worst-Case: O(n log n)

// Raumkomplexität: O(n)
