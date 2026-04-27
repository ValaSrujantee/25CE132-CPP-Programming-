#include <iostream>
using namespace std;

// ---------------------------
// Calculator Class
// ---------------------------
class Calculator {

private:
    double results[10];   // Store results
    int count;

public:

    // Constructor
    Calculator() {
        count = 0;
    }

    // Overloaded add function for integers
    int add(int a, int b) {
        int sum = a + b;
        storeResult(sum);
        return sum;
    }

    // Overloaded add function for floats
    float add(float a, float b) {
        float sum = a + b;
        storeResult(sum);
        return sum;
    }

    // Overloaded add function for mixed types
    double add(int a, float b) {
        double sum = a + b;
        storeResult(sum);
        return sum;
    }

    // Function to store result
    void storeResult(double value) {
        if (count < 10) {
            results[count] = value;
            count++;
        }
    }

    // Display stored results
    void displayResults() {

        cout << "\nStored Results:\n";

        for (int i = 0; i < count; i++) {
            cout << "Result "
                 << i + 1
                 << ": "
                 << results[i]
                 << endl;
        }
    }
};

// ---------------------------
// MAIN FUNCTION
// ---------------------------
int main() {

    Calculator calc;

    int a = 10, b = 20;
    float x = 5.5, y = 4.5;

    cout << "Integer Addition: "
         << calc.add(a, b)
         << endl;

    cout << "Float Addition: "
         << calc.add(x, y)
         << endl;

    cout << "Mixed Addition (int + float): "
         << calc.add(a, x)
         << endl;

    // Display all stored results
    calc.displayResults();

    return 0;
}
