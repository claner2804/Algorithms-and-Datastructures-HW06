/*
Binary Search
 
Zeitkomplexität:
Best-Case: 𝑂(1)
Average-Case: 𝑂(log n)
Worst-Case: 𝑂(log n)

Raumkomplexität: 
 O(1)
 
 */
#include <iostream>
#include <vector>

int binarySearch(const std::vector<int>& arr, int target) {
    int left = 0; // Initialisierung von left (O(1))
    int right = arr.size() - 1; // Initialisierung von right (O(1))
    while (left <= right) { // Schleifenbedingung überprüfen (O(log n) Iterationen)
        int mid = left + (right - left) / 2; // Berechnung von mid (O(1))
        if (arr[mid] == target) { // Vergleich mit dem Ziel (O(1))
            return mid; // Element gefunden (O(1))
        } else if (arr[mid] < target) { // Vergleich mit dem Ziel (O(1))
            left = mid + 1; // Aktualisierung von left (O(1))
        } else { // Vergleich mit dem Ziel (O(1))
            right = mid - 1; // Aktualisierung von right (O(1))
        }
    }
    return -1; // Element nicht gefunden (O(1))
    // Zeitkomplexität vor dem Kürzen:
    // Best-Case: 1 Vergleich -> O(1)
    // Average-Case: log(n) Vergleiche -> O(log n)
    // Worst-Case: log(n) Vergleiche -> O(log n)
    // Nach dem Kürzen:
    // Best-Case: O(1)
    // Average-Case: O(log n)
    // Worst-Case: O(log n)
    // Raumkomplexität: O(1)
}



