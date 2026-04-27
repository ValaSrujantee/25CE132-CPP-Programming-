#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function to add item
void addItem() {
    ofstream file("inventory.txt", ios::app);

    if (!file) {
        cout << "Error: Cannot open file!" << endl;
        return;
    }

    string name;
    int quantity;
    float price;

    cin.ignore();  // Clear input buffer

    cout << "Enter Item Name: ";
    getline(cin, name);

    cout << "Enter Quantity: ";
    cin >> quantity;

    cout << "Enter Price: ";
    cin >> price;

    // Write to file
    file << name << " "
         << quantity << " "
         << price << endl;

    file.close();

    cout << "Item added successfully.\n";
}

// Function to view all items
void viewItems() {
    ifstream file("inventory.txt");

    if (!file) {
        cout << "Error: Cannot open file!" << endl;
        return;
    }

    string name;
    int quantity;
    float price;

    cout << "\n----- Inventory Items -----\n";

    // Read line by line
    while (file >> name >> quantity >> price) {
        cout << "Name: " << name << endl;
        cout << "Quantity: " << quantity << endl;
        cout << "Price: " << price << endl;
        cout << "---------------------------\n";
    }

    file.close();
}

// Function to search item
void searchItem() {
    ifstream file("inventory.txt");

    if (!file) {
        cout << "Error: Cannot open file!" << endl;
        return;
    }

    string searchName;
    string name;
    int quantity;
    float price;

    bool found = false;

    cin.ignore();  // Clear buffer

    cout << "Enter item name to search: ";
    getline(cin, searchName);

    while (file >> name >> quantity >> price) {
        if (name == searchName) {
            cout << "\nItem Found:\n";
            cout << "Name: " << name << endl;
            cout << "Quantity: " << quantity << endl;
            cout << "Price: " << price << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Item not found.\n";
    }

    file.close();
}

int main() {

    int choice;

    do {
        cout << "\n===== Inventory Management System =====\n";
        cout << "1. Add Item\n";
        cout << "2. View All Items\n";
        cout << "3. Search Item by Name\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";

        cin >> choice;

        switch (choice) {

        case 1:
            addItem();
            break;

        case 2:
            viewItems();
            break;

        case 3:
            searchItem();
            break;

        case 4:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}
