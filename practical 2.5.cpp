#include <iostream>
#include <cmath>
using namespace std;

class Loan
{
private:
    int loanID;
    string name;
    double amount;
    double annualRate;
    int tenure;

public:

    // Default Constructor
    Loan()
    {
        loanID = 0;
        name = "Not Assigned";
        amount = 0;
        annualRate = 0;
        tenure = 0;
    }

    // Parameterized Constructor
    Loan(int id, string n, double amt, double rate, int t)
    {
        // Validation checks
        if (amt <= 0)
        {
            cout << "Invalid Loan Amount. Setting to 0.\n";
            amount = 0;
        }
        else
            amount = amt;

        if (rate <= 0)
        {
            cout << "Invalid Interest Rate. Setting to 0.\n";
            annualRate = 0;
        }
        else
            annualRate = rate;

        if (t <= 0)
        {
            cout << "Invalid Tenure. Setting to 0.\n";
            tenure = 0;
        }
        else
            tenure = t;

        loanID = id;
        name = n;
    }

    // Member function to calculate EMI
    double calculateEMI()
    {
        if (amount == 0 || annualRate == 0 || tenure == 0)
            return 0;

        double monthlyRate = annualRate / (12 * 100);

        double emi =
            (amount * monthlyRate * pow(1 + monthlyRate, tenure)) /
            (pow(1 + monthlyRate, tenure) - 1);

        return emi;
    }

    // Function to display loan details
    void display()
    {
        cout << "\nLoan ID: " << loanID;
        cout << "\nApplicant Name: " << name;
        cout << "\nLoan Amount: " << amount;
        cout << "\nAnnual Interest Rate: " << annualRate << "%";
        cout << "\nLoan Tenure (months): " << tenure;
        cout << "\nMonthly EMI: " << calculateEMI();
        cout << "\n-----------------------------";
    }
};

int main()
{
    Loan L1; // Default constructor

    int id, tenure;
    string name;
    double amount, rate;

    cout << "Enter Loan Details\n";

    cout << "Loan ID: ";
    cin >> id;

    cout << "Applicant Name: ";
    cin >> name;

    cout << "Loan Amount: ";
    cin >> amount;

    cout << "Annual Interest Rate (%): ";
    cin >> rate;

    cout << "Loan Tenure (months): ";
    cin >> tenure;

    // Parameterized constructor
    Loan L2(id, name, amount, rate, tenure);

    cout << "\nDefault Loan Details:";
    L1.display();

    cout << "\nEntered Loan Details:";
    L2.display();

    return 0;
}
