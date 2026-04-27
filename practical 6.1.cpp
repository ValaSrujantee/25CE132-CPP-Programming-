#include <iostream>
#include <cmath>   // for pi calculation

using namespace std;

// Base Class
class Shape {
protected:
    double radius;   // Protected data member

public:
    // Setter function (encapsulation)
    void setRadius(double r) {
        if (r > 0)
            radius = r;
        else
            radius = 0;
    }

    // Getter function
    double getRadius() {
        return radius;
    }
};

// Derived Class
class Circle : public Shape {
public:
    // Function to calculate area
    double calculateArea() {
        return 3.14159 * radius * radius;
    }
};

int main() {

    int n;

    cout << "Enter number of circles: ";
    cin >> n;

    // -----------------------------
    // Dynamic Method
    // -----------------------------
    cout << "\n--- Dynamic Array Method ---\n";

    Circle* dynamicCircles = new Circle[n];

    for (int i = 0; i < n; i++) {
        double r;
        cout << "Enter radius of circle " << i + 1 << ": ";
        cin >> r;

        dynamicCircles[i].setRadius(r);
    }

    cout << "\nAreas of Circles (Dynamic):\n";

    for (int i = 0; i < n; i++) {
        cout << "Circle " << i + 1
             << " Area = "
             << dynamicCircles[i].calculateArea()
             << endl;
    }

    // Free dynamic memory
    delete[] dynamicCircles;

    // -----------------------------
    // Static Method
    // -----------------------------
    cout << "\n--- Static Array Method ---\n";

    const int SIZE = 3;
    Circle staticCircles[SIZE];

    for (int i = 0; i < SIZE; i++) {
        double r;
        cout << "Enter radius of circle " << i + 1 << ": ";
        cin >> r;

        staticCircles[i].setRadius(r);
    }

    cout << "\nAreas of Circles (Static):\n";

    for (int i = 0; i < SIZE; i++) {
        cout << "Circle " << i + 1
             << " Area = "
             << staticCircles[i].calculateArea()
             << endl;
    }

    return 0;
}
