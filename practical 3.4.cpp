#include <iostream>
using namespace std;

/* Display Array */
template <class T>
void displayArray(T arr[], int size) {
    cout << "Array elements: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

/* Find Maximum Element */
template <class T>
T findMax(T arr[], int size) {
    T max = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    return max;
}

/* Reverse Array */
template <class T>
void reverseArray(T arr[], int size) {
    for (int i = 0; i < size / 2; i++) {
        T temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
}

/* Find Leader Elements */
template <class T>
void findLeaders(T arr[], int size) {
    cout << "Leader elements: ";

    T leader = arr[size - 1];
    cout << leader << " ";

    for (int i = size - 2; i >= 0; i--) {
        if (arr[i] > leader) {
            leader = arr[i];
            cout << leader << " ";
        }
    }

    cout << endl;
}

int main() {

    /* Integer Array */
    int intArr[] = {16, 17, 4, 3, 5, 2};
    int intSize = 6;

    cout << "\n--- Integer Array ---\n";
    displayArray(intArr, intSize);

    cout << "Maximum value: "
         << findMax(intArr, intSize) << endl;

    reverseArray(intArr, intSize);
    cout << "Reversed array: ";
    displayArray(intArr, intSize);

    findLeaders(intArr, intSize);


    /* Float Array */
    float floatArr[] = {1.2, 3.5, 2.8, 7.4, 6.1};
    int floatSize = 5;

    cout << "\n--- Float Array ---\n";
    displayArray(floatArr, floatSize);

    cout << "Maximum value: "
         << findMax(floatArr, floatSize) << endl;

    reverseArray(floatArr, floatSize);
    cout << "Reversed array: ";
    displayArray(floatArr, floatSize);

    findLeaders(floatArr, floatSize);


    /* Character Array */
    char charArr[] = {'A', 'D', 'B', 'Z', 'C'};
    int charSize = 5;

    cout << "\n--- Character Array ---\n";
    displayArray(charArr, charSize);

    cout << "Maximum value: "
         << findMax(charArr, charSize) << endl;

    reverseArray(charArr, charSize);
    cout << "Reversed array: ";
    displayArray(charArr, charSize);

    findLeaders(charArr, charSize);

    return 0;
}
