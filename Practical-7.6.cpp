#include<iostream>
using namespace std;



// ------------------- CASE 1: WITHOUT VIRTUAL DESTRUCTOR -------------------
class Base1
{
public:

    Base1()
    {
        cout<<"Base1 Constructor\n";
    }

    ~Base1()
    {
        cout<<"Base1 Destructor\n";
    }
};



class Derived1 : public Base1
{
    int *p;

public:

    Derived1()
    {
        cout<<"Derived1 Constructor\n";

        p = new int[5];   // dynamic memory
    }

    ~Derived1()
    {
        cout<<"Derived1 Destructor (Memory Freed)\n";

        delete[] p;
    }
};





// ------------------- CASE 2: WITH VIRTUAL DESTRUCTOR -------------------
class Base2
{
public:

    Base2()
    {
        cout<<"Base2 Constructor\n";
    }

    virtual ~Base2()
    {
        cout<<"Base2 Virtual Destructor\n";
    }
};



class Derived2 : public Base2
{
    int *p;

public:

    Derived2()
    {
        cout<<"Derived2 Constructor\n";

        p = new int[5];
    }

    ~Derived2()
    {
        cout<<"Derived2 Destructor (Memory Freed)\n";

        delete[] p;
    }
};





int main()
{
    int choice;

M:

    cout<<"\n1.Without Virtual Destructor";
    cout<<"\n2.With Virtual Destructor";
    cout<<"\n3.Exit";

    cout<<"\nEnter Choice : ";
    cin>>choice;



    switch(choice)
    {

        case 1:
        {
            cout<<"\n--- CASE 1 OUTPUT ---\n";

            Base1 *b = new Derived1();

            delete b;   // PROBLEM: Derived destructor NOT called

            goto M;
        }



        case 2:
        {
            cout<<"\n--- CASE 2 OUTPUT ---\n";

            Base2 *b = new Derived2();

            delete b;   // CORRECT: both destructors called

            goto M;
        }



        case 3:
            break;



        default:
            cout<<"Invalid Choice\n";
            goto M;
    }

    return 0;
}


// Name : Helly Parmar
// ID : 25CE069
