#include<iostream>
using namespace std;



class BankAccount
{
private:
    long long balance;

public:

    BankAccount()
    {
        balance = 0;
    }



    void deposit(int amt, string logs[], int &idx)
    {
        logs[idx++] = "Deposit function called";

        if(amt <= 0)
        {
            throw "Invalid Deposit Amount";
        }

        balance = balance + amt;

        logs[idx++] = "Deposit successful";
    }



    void withdraw(int amt, string logs[], int &idx)
    {
        logs[idx++] = "Withdraw function called";

        if(amt <= 0)
        {
            throw "Invalid Withdraw Amount";
        }

        if(amt > balance)
        {
            throw "Insufficient Balance";
        }

        balance = balance - amt;

        logs[idx++] = "Withdraw successful";
    }



    void showBalance()
    {
        cout<<"Balance = "<<balance<<endl;
    }
};




int main()
{
    BankAccount acc;

    string logs[50];
    int idx = 0;

    int ch, amt;

    try
    {
        cout<<"1.Deposit\n2.Withdraw\nEnter choice : ";
        cin>>ch;

        if(cin.fail())
        {
            throw "Invalid Input";
        }



        if(ch == 1)
        {
            cout<<"Enter amount : ";
            cin>>amt;

            acc.deposit(amt, logs, idx);
        }
        else if(ch == 2)
        {
            cout<<"Enter amount : ";
            cin>>amt;

            acc.withdraw(amt, logs, idx);
        }
        else
        {
            throw "Invalid Choice";
        }



        acc.showBalance();
    }



    catch(const char* msg)
    {
        cout<<"\nException: "<<msg<<endl;
        cout<<"Program terminated due to error\n";
    }



    cout<<"\n--- Logs ---\n";

    for(int i=0; i<idx; i++)
    {
        cout<<logs[i]<<endl;
    }



    return 0;
}


// Name : Helly Parmar
// ID : 25CE069
