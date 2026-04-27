#include <iostream>
#include <string>

using namespace std;

// ---------------------------
// Base Class 1: Fuel
// ---------------------------
class Fuel {
protected:
    string fuelType;

public:
    // Constructor
    Fuel(string f) {
        fuelType = f;
    }

    void displayFuel() {
        cout << "Fuel Type: " << fuelType << endl;
    }
};

// ---------------------------
// Base Class 2: Brand
// ---------------------------
class Brand {
protected:
    string brandName;

public:
    // Constructor
    Brand(string b) {
        brandName = b;
    }

    void displayBrand() {
        cout << "Brand Name: " << brandName << endl;
    }
};

// ---------------------------
// Derived Class: Car
// (Multiple / Hybrid Inheritance)
// ---------------------------
class Car : public Fuel, public Brand {

public:
    // Constructor chaining
    Car(string f, string b)
        : Fuel(f), Brand(b)
    {
        // Nothing extra here
    }

    // Display complete car details
    void displayCar() {
        displayFuel();
        displayBrand();
        cout << "-----------------------" << endl;
    }
};

// ---------------------------
// Simple Queue Implementation
// ---------------------------
class CarQueue {

private:
    static const int MAX = 5;
    Car* queue[MAX];
    int front;
    int rear;

public:
    CarQueue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return (front == -1);
    }

    bool isFull() {
        return (rear == MAX - 1);
    }

    void enqueue(Car* c) {

        if (isFull()) {
            cout << "Queue is full!" << endl;
            return;
        }

        if (isEmpty())
            front = 0;

        rear++;
        queue[rear] = c;
    }

    void displayQueue() {

        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }

        cout << "\n--- Cars in Queue ---\n";

        for (int i = front; i <= rear; i++) {
            queue[i]->displayCar();
        }
    }
};

// ---------------------------
// MAIN FUNCTION
// ---------------------------
int main() {

    cout << "=== Static Storage Method ===\n";

    // Static method
    const int SIZE = 3;

    Car cars[SIZE] = {
        Car("Petrol", "Toyota"),
        Car("Diesel", "Mahindra"),
        Car("Electric", "Tata")
    };

    for (int i = 0; i < SIZE; i++) {
        cars[i].displayCar();
    }

    // Queue-based structured approach
    cout << "\n=== Queue-Based Structured Method ===\n";

    CarQueue serviceQueue;

    Car c1("Petrol", "Hyundai");
    Car c2("Electric", "MG");
    Car c3("Diesel", "Kia");

    serviceQueue.enqueue(&c1);
    serviceQueue.enqueue(&c2);
    serviceQueue.enqueue(&c3);

    serviceQueue.displayQueue();

    return 0;
}
