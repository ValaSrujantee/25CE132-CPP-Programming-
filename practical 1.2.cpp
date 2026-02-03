#include <iostream>
#include <string>
using namespace std;

class Library {
private:
    int b_ID;
    string b_title;
    string b_author;
    int b_num;       // available copies
    int issued;      // 0 = not issued, 1 = issued

public:
    void add_book();
    int getID();
    bool matchTitle(string);
    bool matchAuthor(string);
    bool issue_book();
    bool return_book();
    void display_book();
};

void Library::add_book() {
    cout << "Enter book ID: ";
    cin >> b_ID;

    cout << "Enter book title: ";
    cin >> b_title;

    cout << "Enter book author: ";
    cin >> b_author;

    cout << "Enter number of copies: ";
    cin >> b_num;

    issued = 0;
}

int Library::getID() {
    return b_ID;
}

bool Library::matchTitle(string t) {
    return (t == b_title);
}

bool Library::matchAuthor(string a) {
    return (a == b_author);
}

bool Library::issue_book() {
    if (issued == 1) {
        cout << "Error: This book is already issued.\n";
        return true;
    }

    if (b_num > 0) {
        b_num--;
        issued = 1;
        cout << "Book issued successfully: " << b_title << endl;
        return true;
    }

    cout << "Error: No copies available.\n";
    return true;
}

bool Library::return_book() {
    if (issued == 0) {
        cout << "Error: This book was not issued.\n";
        return true;
    }

    b_num++;
    issued = 0;
    cout << "Book returned successfully: " << b_title << endl;
    return true;
}

void Library::display_book() {
    cout << "\nBook ID: " << b_ID
         << "\nTitle: " << b_title
         << "\nAuthor: " << b_author
         << "\nAvailable copies: " << b_num
         << "\nStatus: " << (issued ? "Issued" : "Available") << endl;
}

int main() {
    Library B[100];
    int choice, last = 0;
    int id;
    string name;
    bool found;

    while (true) {
        cout << "\n\n1. Add Book";
        cout << "\n2. Issue Book";
        cout << "\n3. Return Book";
        cout << "\n4. Display All Books";
        cout << "\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            B[last].add_book();
            last++;
            break;

        case 2:
            cout << "Enter book ID to issue: ";
            cin >> id;
            found = false;

            for (int i = 0; i < last; i++) {
                if (B[i].getID() == id) {
                    B[i].issue_book();
                    found = true;
                    break;
                }
            }

            if (!found)
                cout << "Error: Book ID does not exist.\n";
            break;

        case 3:
            cout << "Enter book ID to return: ";
            cin >> id;
            found = false;

            for (int i = 0; i < last; i++) {
                if (B[i].getID() == id) {
                    B[i].return_book();
                    found = true;
                    break;
                }
            }

            if (!found)
                cout << "Error: Book ID does not exist.\n";
            break;

        case 4:
            if (last == 0) {
                cout << "No books available.\n";
            } else {
                for (int i = 0; i < last; i++)
                    B[i].display_book();
            }
            break;

        case 5:
            return 0;

        default:
            cout << "Invalid choice!\n";
        }
    }
}
