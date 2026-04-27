#include <iostream>
#include <string>

using namespace std;

// ---------------------------
// Base Class: Account
// ---------------------------
class Account {

private:
    int accountNumber;
    double balance;

protected:
    // Transaction history storage
    string transactions[10];
    int transactionCount;

public:

    // Constructor
    Account(int accNo, double bal) {
        accountNumber = accNo;
        balance = bal;
        transactionCount = 0;
        cout << "Account Created\n";
    }

    // Destructor
    ~Account() {
        cout << "Account Closed\n";
    }

    // Deposit function
    void deposit(double amount) {
        balance += amount;

        if (transactionCount < 10) {
            transactions[transactionCount] =
                "Deposited: " + to_string(amount);
            transactionCount++;
        }

        cout << "Amount Deposited Successfully\n";
    }

    // Withdraw function
    virtual void withdraw(double amount) {

        if (amount <= balance) {
            balance -= amount;

            if (transactionCount < 10) {
                transactions[transactionCount] =
                    "Withdrawn: " + to_string(amount);
                transactionCount++;
            }

            cout << "Amount Withdrawn Successfully\n";
        }
        else {
            cout << "Insufficient Balance\n";
        }
    }

    // Undo last transaction
    void undoLastTransaction() {

        if (transactionCount == 0) {
            cout << "No transaction to undo\n";
            return;
        }

        string last = transactions[transactionCount - 1];

        // Simple undo logic
        if (last.find("Deposited") != string::npos) {
            double amount =
                stod(last.substr(11));
            balance -= amount;
        }
        else if (last.find("Withdrawn") != string::npos) {
            double amount =
                stod(last.substr(11));
            balance += amount;
        }

        transactionCount--;

        cout << "Last transaction undone\n";
    }

    // Display transaction history
    void showTransactions() {

        cout << "\nTransaction History:\n";

        for (int i = 0; i < transactionCount; i++) {
            cout << transactions[i] << endl;
        }
    }

    // Display account details
    void display() {
        cout << "Account Number: "
             << accountNumber << endl;

        cout << "Current Balance: "
             << balance << endl;
    }
};

// ---------------------------
// Derived Class: SavingsAccount
// ---------------------------
class SavingsAccount : public Account {

private:
    double interestRate;

public:

    // Constructor
    SavingsAccount(int accNo,
                   double bal,
                   double rate)
        : Account(accNo, bal)
    {
        interestRate = rate;
        cout << "Savings Account Created\n";
    }

    // Destructor
    ~SavingsAccount() {
        cout << "Savings Account Destroyed\n";
    }

    void display() {
        Account::display();
        cout << "Interest Rate: "
             << interestRate
             << "%" << endl;
    }
};

// ---------------------------
// Derived Class: CurrentAccount
// ---------------------------
class CurrentAccount : public Account {

private:
    double overdraftLimit;

public:

    // Constructor
    CurrentAccount(int accNo,
                   double bal,
                   double limit)
        : Account(accNo, bal)
    {
        overdraftLimit = limit;
        cout << "Current Account Created\n";
    }

    // Destructor
    ~CurrentAccount() {
        cout << "Current Account Destroyed\n";
    }

    // Withdraw with overdraft
    void withdraw(double amount) {

        if (amount <= overdraftLimit) {

            // allow negative balance
            cout << "Withdrawn using overdraft\n";

            // call base withdraw logic
            Account::withdraw(amount);
        }
        else {
            cout << "Overdraft limit exceeded\n";
        }
    }

    void display() {
        Account::display();
        cout << "Overdraft Limit: "
             << overdraftLimit << endl;
    }
};

// ---------------------------
// MAIN FUNCTION
// ---------------------------
int main() {

    // Create accounts
    SavingsAccount s1(101, 5000, 5.0);
    CurrentAccount c1(201, 3000, 10000);

    cout << "\n--- Savings Account Operations ---\n";

    s1.deposit(1000);
    s1.withdraw(500);
    s1.display();
    s1.showTransactions();

    s1.undoLastTransaction();

    cout << "\nAfter Undo:\n";
    s1.display();

    cout << "\n--- Current Account Operations ---\n";

    c1.deposit(2000);
    c1.withdraw(4000);
    c1.display();
    c1.showTransactions();

    return 0;
}
