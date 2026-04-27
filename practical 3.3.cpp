#include <iostream>
#include <string>
using namespace std;

class Account {
private:
    int accountNumber;
    string holderName;
    double balance;

public:
    // Static data member to track total accounts
    static int totalAccounts;

    // Constructor
    Account() {
        accountNumber = 0;
        holderName = "";
        balance = 0.0;
    }

    // Function to create account
    void createAccount() {
        cout << "Enter Account Number: ";
        cin >> accountNumber;

        cin.ignore();
        cout << "Enter Account Holder Name: ";
        getline(cin, holderName);

        cout << "Enter Initial Balance: ";
        cin >> balance;

        totalAccounts++;
    }

    // Function to update account details
    void updateAccount() {
        cout << "Enter New Holder Name: ";
        cin.ignore();
        getline(cin, holderName);

        cout << "Enter New Balance: ";
        cin >> balance;
    }

    // Function to display account details
    void displayAccount() {
        cout << "\nAccount Number: " << accountNumber << endl;
        cout << "Account Holder Name: " << holderName << endl;
        cout << "Current Balance: " << balance << endl;
    }

    // Getter for account number
    int getAccountNumber() {
        return accountNumber;
    }

    // Getter for balance
    double getBalance() {
        return balance;
    }

    // Setter for balance
    void setBalance(double amount) {
        balance = amount;
    }

    // Static function to display total accounts
    static void showTotalAccounts() {
        cout << "\nTotal Accounts Created: " << totalAccounts << endl;
    }
};

// Initialize static member
int Account::totalAccounts = 0;

// Function to find account
Account* findAccount(Account* accounts[], int size, int accNo) {
    for (int i = 0; i < size; i++) {
        if (accounts[i] != NULL &&
            accounts[i]->getAccountNumber() == accNo) {
            return accounts[i];
        }
    }
    return NULL;
}

// Function to transfer funds
void transferFunds(Account* accounts[], int size) {
    int fromAcc, toAcc;
    double amount;

    cout << "Enter Sender Account Number: ";
    cin >> fromAcc;

    cout << "Enter Receiver Account Number: ";
    cin >> toAcc;

    Account* sender = findAccount(accounts, size, fromAcc);
    Account* receiver = findAccount(accounts, size, toAcc);

    // Validation
    if (sender == NULL || receiver == NULL) {
        cout << "Invalid account number!" << endl;
        return;
    }

    cout << "Enter Amount to Transfer: ";
    cin >> amount;

    if (amount <= 0) {
        cout << "Invalid transfer amount!" << endl;
        return;
    }

    if (sender->getBalance() < amount) {
        cout << "Insufficient balance!" << endl;
        return;
    }

    // Transfer
    sender->setBalance(sender->getBalance() - amount);
    receiver->setBalance(receiver->getBalance() + amount);

    cout << "Transfer Successful!" << endl;
}

int main() {
    int maxAccounts = 100;
    Account* accounts[100] = {NULL};

    int choice;
    int index = 0;
    int accNo;

    do {
        cout << "\n===== Bank Account Management System =====\n";
        cout << "1. Add Account\n";
        cout << "2. Update Account\n";
        cout << "3. Display Account\n";
        cout << "4. Transfer Funds\n";
        cout << "5. Show Total Accounts\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            if (index < maxAccounts) {
                accounts[index] = new Account(); // Dynamic allocation
                accounts[index]->createAccount();
                index++;
            } else {
                cout << "Account limit reached!" << endl;
            }
            break;

        case 2:
            cout << "Enter Account Number to Update: ";
            cin >> accNo;

            if (Account* acc = findAccount(accounts, index, accNo)) {
                acc->updateAccount();
            } else {
                cout << "Account not found!" << endl;
            }
            break;

        case 3:
            cout << "Enter Account Number to Display: ";
            cin >> accNo;

            if (Account* acc = findAccount(accounts, index, accNo)) {
                acc->displayAccount();
            } else {
                cout << "Account not found!" << endl;
            }
            break;

        case 4:
            transferFunds(accounts, index);
            break;

        case 5:
            Account::showTotalAccounts();
            break;

        case 6:
            cout << "Exiting program..." << endl;
            break;

        default:
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 6);

    // Free memory
    for (int i = 0; i < index; i++) {
        delete accounts[i];
    }

    return 0;
}
