#include <iostream>
#include <iomanip>   // For setw, setfill, setprecision

using namespace std;

// User-defined manipulator
ostream& currency(ostream& output) {
    output << "₹ ";
    return output;
}

int main() {

    // Student data
    string names[] = {"Amit", "Neha", "Rahul", "Priya"};
    int marks[] = {85, 92, 78, 88};
    double fees[] = {25000.5, 26000.75, 24500.0, 25500.25};

    int n = 4;

    // Table header
    cout << setfill('=');
    cout << setw(50) << "=" << endl;

    cout << setfill(' ');

    cout << setw(10) << "Name"
         << setw(10) << "Marks"
         << setw(15) << "Fees"
         << endl;

    cout << setfill('-');
    cout << setw(50) << "-" << endl;

    cout << setfill(' ');

    // Display student data
    for (int i = 0; i < n; i++) {

        cout << setw(10) << names[i]
             << setw(10) << marks[i]
             << setw(5) << currency
             << setw(10) << fixed << setprecision(2)
             << fees[i]
             << endl;
    }

    cout << setfill('=');
    cout << setw(50) << "=" << endl;

    return 0;
}
