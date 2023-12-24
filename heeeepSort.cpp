#include <iostream>
#include "HashTable.h"

using namespace std;

// Function to heapify a subtree rooted with the given node
void heapify(fileNode arr[], int n, int i) {
    int largest = i;  // Initialize the root as the largest
    int left_child = 2 * i + 1;
    int right_child = 2 * i + 2;

    // Check if the left child exists and is greater than the root
    if (left_child < n && arr[left_child].count > arr[largest].count) {
        largest = left_child;
    }

    // Check if the right child exists and is greater than the current largest
    if (right_child < n && arr[right_child].count > arr[largest].count) {
        largest = right_child;
    }

    // Swap the root (largest) with the largest child if needed
    if (largest != i) {
        swap(arr[i], arr[largest]);
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// Function to perform heap sort on the array
void heapSort(fileNode arr[], int n) {
    // Build a max-heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Extract elements one by one
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);  // Swap the root (max) with the last element
        heapify(arr, i, 0);    // Heapify the reduced heap
    }
}

