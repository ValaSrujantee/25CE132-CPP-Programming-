#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>

using namespace std;
using namespace std::chrono;

int recursiveSum(int arr[], int n) {
    if (n == 0)
        return 0;
    return arr[n - 1] + recursiveSum(arr, n - 1);
}

int iterativeSum(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    return sum;
}

int main() {
    int n;
    cout << "Enter array size: ";
    cin >> n;

    int* arr = new int[n];

    srand(time(0));
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 100;

    int recursiveLimit = 5000; // limit for recursion

    int resultRecursive = 0;
    int resultIterative = 0;

    // Recursive sum on first 5000 elements or less
    int recSize = (n > recursiveLimit) ? recursiveLimit : n;

    auto start1 = high_resolution_clock::now();
    resultRecursive = recursiveSum(arr, recSize);
    auto end1 = high_resolution_clock::now();

    // Iterative sum on full array
    auto start2 = high_resolution_clock::now();
    resultIterative = iterativeSum(arr, n);
    auto end2 = high_resolution_clock::now();

    auto recursiveTime = duration_cast<microseconds>(end1 - start1);
    auto iterativeTime = duration_cast<microseconds>(end2 - start2);

    cout << "Recursive Sum (first " << recSize << " elements): " << resultRecursive << endl;
    cout << "Iterative Sum (all " << n << " elements): " << resultIterative << endl;

    cout << "Recursive Time: " << recursiveTime.count() << " microseconds\n";
    cout << "Iterative Time: " << iterativeTime.count() << " microseconds\n";

    delete[] arr;
    return 0;
}
