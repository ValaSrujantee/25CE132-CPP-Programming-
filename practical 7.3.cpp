#include <iostream>
#include <queue>
using namespace std;

// Forward declaration
class Fahrenheit;

// --------------------------
// Celsius Class
// --------------------------
class Celsius {

private:
    float tempC;

public:

    // Constructor
    Celsius(float c = 0) {
        tempC = c;
    }

    // Type conversion: Celsius -> Fahrenheit
    operator Fahrenheit();

    float getTemp() {
        return tempC;
    }

    void display() {
        cout << tempC << " °C";
    }
};

// --------------------------
// Fahrenheit Class
// --------------------------
class Fahrenheit {

private:
    float tempF;

public:

    // Constructor
    Fahrenheit(float f = 0) {
        tempF = f;
    }

    // Type conversion: Fahrenheit -> Celsius
    operator Celsius() {
        float c;
        c = (5.0 / 9) * (tempF - 32);
        return Celsius(c);
    }

    // Equality operator overload
    bool operator == (Fahrenheit f) {
        return tempF == f.tempF;
    }

    float getTemp() {
        return tempF;
    }

    void display() {
        cout << tempF << " °F";
    }
};

// Definition of conversion outside class
Celsius::operator Fahrenheit() {

    float f;
    f = (9.0 / 5) * tempC + 32;

    return Fahrenheit(f);
}

// --------------------------
// MAIN FUNCTION
// --------------------------
int main() {

    cout << "=== Temperature Conversion System ===\n";

    // Basic conversion
    Celsius c1(25);
    Fahrenheit f1;

    f1 = c1;   // Celsius -> Fahrenheit

    cout << "\nCelsius to Fahrenheit:\n";
    c1.display();
    cout << " = ";
    f1.display();

    // Reverse conversion
    Fahrenheit f2(77);
    Celsius c2;

    c2 = f2;   // Fahrenheit -> Celsius

    cout << "\n\nFahrenheit to Celsius:\n";
    f2.display();
    cout << " = ";
    c2.display();

    // Equality comparison
    Fahrenheit f3(77);

    cout << "\n\nTemperature Comparison:\n";

    if (f2 == f3)
        cout << "Temperatures are Equal\n";
    else
        cout << "Temperatures are Not Equal\n";

    // --------------------------
    // Dynamic Queue (FIFO)
    // --------------------------
    queue<Fahrenheit> tempQueue;

    tempQueue.push(Fahrenheit(68));
    tempQueue.push(Fahrenheit(86));
    tempQueue.push(Fahrenheit(104));

    cout << "\nQueue Processing (FIFO):\n";

    while (!tempQueue.empty()) {

        Fahrenheit temp = tempQueue.front();

        temp.display();
        cout << endl;

        tempQueue.pop();
    }

    // --------------------------
    // Static Array Storage
    // --------------------------
    Celsius tempArray[3] = {
        Celsius(10),
        Celsius(20),
        Celsius(30)
    };

    cout << "\nStatic Array Storage:\n";

    for (int i = 0; i < 3; i++) {

        tempArray[i].display();
        cout << endl;
    }

    return 0;
}
