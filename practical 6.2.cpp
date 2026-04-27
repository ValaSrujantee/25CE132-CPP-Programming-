#include <iostream>
#include <string>

using namespace std;

// ---------------------------
// Base Class: Person
// ---------------------------
class Person {
protected:
    string name;
    int age;

public:
    // Constructor
    Person(string n, int a) {
        name = n;
        age = a;
    }

    // Display function
    void displayPerson() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

// ---------------------------
// Intermediate Class: Employee
// ---------------------------
class Employee : public Person {
protected:
    int empID;

public:
    // Constructor chaining
    Employee(string n, int a, int id)
        : Person(n, a)   // Calls base class constructor
    {
        empID = id;
    }

    // Display function
    void displayEmployee() {
        displayPerson();
        cout << "Employee ID: " << empID << endl;
    }

    // Getter for ID (used in retrieval)
    int getID() {
        return empID;
    }
};

// ---------------------------
// Top Level Class: Manager
// ---------------------------
class Manager : public Employee {
private:
    string department;

public:
    // Constructor chaining
    Manager(string n, int a, int id, string dept)
        : Employee(n, a, id)
    {
        department = dept;
    }

    // Display full hierarchy
    void displayManager() {
        displayEmployee();
        cout << "Department: " << department << endl;
        cout << "---------------------------" << endl;
    }
};

// ---------------------------
// MAIN FUNCTION
// ---------------------------
int main() {

    const int SIZE = 3;

    // Static storage method
    Manager managers[SIZE] = {
        Manager("Amit", 35, 101, "Sales"),
        Manager("Neha", 40, 102, "HR"),
        Manager("Rahul", 38, 103, "IT")
    };

    cout << "=== All Managers (Static Storage) ===\n";

    for (int i = 0; i < SIZE; i++) {
        managers[i].displayManager();
    }

    // Identifier-based retrieval method
    int searchID;
    bool found = false;

    cout << "\nEnter Employee ID to search: ";
    cin >> searchID;

    for (int i = 0; i < SIZE; i++) {

        if (managers[i].getID() == searchID) {

            cout << "\nManager Found:\n";
            managers[i].displayManager();
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Manager with given ID not found.\n";
    }

    return 0;
}
