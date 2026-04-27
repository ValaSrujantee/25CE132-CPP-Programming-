#include<iostream>
using namespace std;

int main()
{
    int a, b;

    try
    {
        cout<<"Enter numerator : ";
        cin>>a;

        if(cin.fail())
        {
            throw "Invalid Input: Numerator must be integer";
        }


        cout<<"Enter denominator : ";
        cin>>b;

        if(cin.fail())
        {
            throw "Invalid Input: Denominator must be integer";
        }


        if(b == 0)
        {
            throw "Division by Zero Error";
        }


        float result = (float)a / b;

        cout<<"Result = "<<result<<endl;
    }


    catch(const char* msg)
    {
        cout<<"Error: "<<msg<<endl;
    }


    catch(...)
    {
        cout<<"Unknown Error Occurred"<<endl;
    }


    // clear input buffer if error happened
    cin.clear();

    return 0;
}


// Name : Helly Parmar
// ID : 25CE069
