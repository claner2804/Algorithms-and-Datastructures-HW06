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
    int left = 0;
    int right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1; // Element nicht gefunden
    // Zeitkomplexität vor dem Kürzen:
    // Best-Case: 1 Vergleich
    // Average-Case: log n Vergleiche
    // Worst-Case: log n Vergleiche
    // Nach dem Kürzen:
    // Best-Case: O(1)
    // Average-Case: O(log n)
    // Worst-Case: O(log n)
    // Raumkomplexität: O(1)
}


