#include<iostream>
#include<cmath>
using namespace std;



class NegativeNumberException
{
public:
    void showError()
    {
        cout<<"Error: Negative number not allowed for square root\n";
    }
};



int main()
{
    float num, result;

    try
    {
        cout<<"Enter a number : ";
        cin>>num;

        if(cin.fail())
        {
            throw "Invalid Input";
        }

        if(num < 0)
        {
            throw NegativeNumberException();
        }

        result = sqrt(num);

        cout<<"Square Root = "<<result<<endl;
    }

    catch(NegativeNumberException e)
    {
        e.showError();
    }

    catch(const char* msg)
    {
        cout<<"Error: "<<msg<<endl;
    }

    return 0;
}


// Name : Helly Parmar
// ID : 25CE069
