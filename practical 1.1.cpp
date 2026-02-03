#include<iostream>
using namespace std;
class bank_account
{
    long double acc_balance;
    char acc_holdersName;
    long double acc_IDNo;
public:
    void create_account();
    int search_ID(int);
    void deposit_money();
    void withdraw_money();
    void check_balance();
};
void bank_account::create_account()
{
    cout<<"Enter the Account ID NO.: ";
    cin>>acc_IDNo;
    cout<<"Enter the Account holder's Name: ";
    cin>>acc_holdersName;
    cout<<"Enter the Account Balance: ";
    cin>>acc_balance;
}
int bank_account::search_ID(int AccID)
{
    if (acc_IDNo == AccID)
        return 1;
    else
        return 0;
}
void bank_account::deposit_money()
{
    double amount;
    cout<<"Enter amount to deposit: ";
    cin>>amount;
    acc_balance += amount;
    cout<<"Money deposited successfully";
}

void bank_account::withdraw_money()
{
    double amount;
    cout<<"Enter amount to withdraw: ";
    cin>>amount;

    if (amount <= acc_balance)
    {
        acc_balance -= amount;
        cout<<"Withdrawal successful";
    }
    else
    {
        cout<<"Insufficient balance";
    }
}
void bank_account::check_balance()
{
    cout<< "Account Holder Name: " <<acc_holdersName<<endl;
    cout<< "Account ID: " <<acc_IDNo<<endl;
    cout<< "Account Balance: "<<acc_balance<<endl;
}

int main()
{
    bank_account b[5];
    int choice,i;
    int AccID,t=0;
    double amount;
N:
    cout<<"\nBANK MENU\n";
    cout<<"1.Create Account\n";
    cout<<"2.Deposit Money\n";
    cout<<"3.Withdraw Money\n";
    cout<<"4.Check Balance\n";
    cout<<"5.Exit\n";
    cout<<"Enter your choice: ";
    cin>>choice;

    switch (choice)
    {
    case 1:
        b[t].create_account();
        t++;
        goto N;

    case 2:
        cout<<"Enter the Id number: ";
        cin>>AccID;
        for(i=0; i<t; i++)
        {
            if(b[i].search_ID(AccID)== 1)
            {
                b[i].deposit_money();
                break;
            }
        }
        if(i==t)
        {
            cout<<"Account Not Found";
        }
        goto N;
    case 3:
        cout<<"Enter the Id number: ";
        cin>>AccID;
        for(i=0; i<t; i++)
        {
            if(b[i].search_ID(AccID)== 1)
            {
                b[i].withdraw_money();
                break;
            }
        }
        if(i==t)
        {
            cout<<"Account Not Found";
        }
        goto N;

    case 4:
        cout<<"Enter the Id number: ";
        cin>>AccID;
        for(i=0; i<t; i++)
        {
            if(b[i].search_ID(AccID)== 1)
            {
                b[i].check_balance();
                break;
            }
        }
        if(i==t)
        {
            cout<<"Account Not Found";
        }
        goto N;
    case 5:
        cout << "Thank you for using the bank system.\n";
        break;

    default:
        cout << "Invalid choice! Try again.\n";
    }

return 0;
}
