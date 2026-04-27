#include <iostream>
using namespace std;

int main() {
    int n, m;

    // Step 1: Read sizes of arrays
    cout << "Enter size of first sorted array: ";
    cin >> n;

    cout << "Enter size of second sorted array: ";
    cin >> m;

    // Step 2: Dynamically allocate arrays
    int* arr1 = new int[n];
    int* arr2 = new int[m];

    // Input elements for first array
    cout << "Enter elements of first sorted array:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }

    // Input elements for second array
    cout << "Enter elements of second sorted array:\n";
    for (int i = 0; i < m; i++) {
        cin >> arr2[i];
    }

    // Step 3: Create merged array
    int* merged = new int[n + m];

    int i = 0, j = 0, k = 0;

    // Merge arrays using linear traversal
    while (i < n && j < m) {
        if (arr1[i] < arr2[j]) {
            merged[k] = arr1[i];
            i++;
        }
        else {
            merged[k] = arr2[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of arr1
    while (i < n) {
        merged[k] = arr1[i];
        i++;
        k++;
    }

    // Copy remaining elements of arr2
    while (j < m) {
        merged[k] = arr2[j];
        j++;
        k++;
    }

    // Step 4: Display merged array
    cout << "Merged Sorted Array:\n";
    for (int t = 0; t < n + m; t++) {
        cout << merged[t] << " ";
    }

    cout << endl;

    // Step 5: Free memory
    delete[] arr1;
    delete[] arr2;
    delete[] merged;

    return 0;
}
