#include <iostream>
using namespace std;

class University
{
private:
    int id;
    string name;
    float m1, m2, m3, avg;

public:
    University();
    void add_student_data();
    float average(float, float, float);
    void display_data();
};

University::University()
{
    id = 0;
    name = "";
    m1 = m2 = m3 = avg = 0;
}

void University::add_student_data()
{
    cout << "Enter ID: ";
    cin >> id;
    cout << "Enter Name: ";
    cin >> name;
    cout << "Enter Marks 1: ";
    cin >> m1;
    cout << "Enter Marks 2: ";
    cin >> m2;
    cout << "Enter Marks 3: ";
    cin >> m3;
    avg = average(m1, m2, m3);
}

float University::average(float a, float b, float c)
{
    return (a + b + c) / 3.0;
}

void University::display_data()
{
    cout << "\nID: " << id;
    cout << "\nName: " << name;
    cout << "\nMarks: " << m1 << ", " << m2 << ", " << m3;
    cout << "\nAverage: " << avg << endl;
}

int main()
{
    University u[100];
    int choice, count = 0;

    while (true)
    {
        cout << "\n--- MENU ---";
        cout << "\n1. Add student data";
        cout << "\n2. Display student data";
        cout << "\n3. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            u[count].add_student_data();
            count++;
            break;

        case 2:
            if (count == 0)
            {
                cout << "No student data available.\n";
            }
            else
            {
                for (int i = 0; i < count; i++)
                {
                    u[i].display_data();
                }
            }
            break;

        case 3:
            return 0;

        default:
            cout << "Invalid choice!";
        }
    }
}
