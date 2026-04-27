#include <iostream>
using namespace std;

// ---------------------------
// Complex Class
// ---------------------------
class Complex {

private:
    double real;
    double imag;

public:

    // Constructor
    Complex(double r = 0, double i = 0) {
        real = r;
        imag = i;
    }

    // Overload + operator
    Complex operator + (Complex c) {

        Complex temp;

        temp.real = real + c.real;
        temp.imag = imag + c.imag;

        return temp;
    }

    // Overload - operator
    Complex operator - (Complex c) {

        Complex temp;

        temp.real = real - c.real;
        temp.imag = imag - c.imag;

        return temp;
    }

    // Display function
    void display() {

        cout << real;

        if (imag >= 0)
            cout << " + " << imag << "i";
        else
            cout << " - " << -imag << "i";

        cout << endl;
    }
};

// ---------------------------
// MAIN FUNCTION
// ---------------------------
int main() {

    Complex c1(4, 5);
    Complex c2(2, 3);

    Complex sum, diff;

    cout << "First Complex Number: ";
    c1.display();

    cout << "Second Complex Number: ";
    c2.display();

    // Operator overloading usage
    sum = c1 + c2;
    diff = c1 - c2;

    cout << "\nAddition Result: ";
    sum.display();

    cout << "Subtraction Result: ";
    diff.display();

    // Optional batch operations
    cout << "\n--- Batch Operations ---\n";

    Complex numbers[3] = {
        Complex(1, 2),
        Complex(3, 4),
        Complex(5, 6)
    };

    for (int i = 0; i < 3; i++) {

        cout << "Complex " << i + 1 << ": ";
        numbers[i].display();
    }

    return 0;
}
