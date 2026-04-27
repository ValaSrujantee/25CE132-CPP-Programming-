#include <iostream>
#include <string>
using namespace std;

class Employee
{
private:
    string name;
    float basicSalary;
    float bonus;

public:
    // Constructor with default bonus
    Employee(string n, float b)
    {
        name = n;
        basicSalary = b;
        bonus = 1000; // default bonus
    }

    // Constructor with custom bonus
    Employee(string n, float b, float bo)
    {
        name = n;
        basicSalary = b;
        bonus = bo;
    }

    // Inline function to calculate total salary
    inline float calculateSalary()
    {
        return basicSalary + bonus;
    }

    // Function to display employee details
    void display()
    {
        cout << "\nEmployee Name: " << name;
        cout << "\nBasic Salary: " << basicSalary;
        cout << "\nBonus: " << bonus;
        cout << "\nTotal Salary: " << calculateSalary();
        cout << "\n---------------------------";
    }
};

int main()
{
    int n;
    cout << "Enter number of employees: ";
    cin >> n;

    // Dynamic storage of employees
    Employee* emp[n];

    string name;
    float basic, bonus;
    int choice;

    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter details for Employee " << i + 1;

        cout << "\nName: ";
        cin >> name;

        cout << "Basic Salary: ";
        cin >> basic;

        cout << "Use default bonus? (1-Yes / 2-No): ";
        cin >> choice;

        if (choice == 1)
        {
            emp[i] = new Employee(name, basic);
        }
        else
        {
            cout << "Enter custom bonus: ";
            cin >> bonus;
            emp[i] = new Employee(name, basic, bonus);
        }
    }

    cout << "\n\nEmployee Details:\n";

    for (int i = 0; i < n; i++)
    {
        emp[i]->display();
    }

    // Free memory
    for (int i = 0; i < n; i++)
    {
        delete emp[i];
    }

    return 0;
}
