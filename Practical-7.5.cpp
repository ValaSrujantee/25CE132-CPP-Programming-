#include<iostream>
using namespace std;



class Student
{
protected:
    int marks;

public:

    Student()
    {
        marks = 0;
    }

    Student(int m)
    {
        marks = m;
    }



    void getMarks()
    {
        while(true)
        {
            cout<<"Enter Marks (0-100) : ";
            cin>>marks;

            if(marks < 0 || marks > 100)
            {
                cout<<"Invalid Marks! Try again\n";
            }
            else
            {
                break;
            }
        }
    }



    virtual void showGrade() = 0;
};




class UG : public Student
{
public:

    void showGrade()
    {
        cout<<"UG Marks : "<<marks<<endl;

        if(marks >= 75)
            cout<<"Grade : A\n";
        else if(marks >= 60)
            cout<<"Grade : B\n";
        else if(marks >= 40)
            cout<<"Grade : C\n";
        else
            cout<<"Grade : Fail\n";
    }
};




class PG : public Student
{
public:

    void showGrade()
    {
        cout<<"PG Marks : "<<marks<<endl;

        if(marks >= 80)
            cout<<"Grade : A+\n";
        else if(marks >= 70)
            cout<<"Grade : A\n";
        else if(marks >= 60)
            cout<<"Grade : B\n";
        else
            cout<<"Grade : Fail\n";
    }
};




int main()
{
    Student *s[10];

    int n, i, type;



    cout<<"Enter number of students : ";
    cin>>n;



    for(i=0;i<n;i++)
    {
        cout<<"\n1.UG  2.PG : ";
        cin>>type;

        if(type == 1)
            s[i] = new UG();
        else
            s[i] = new PG();

        s[i]->getMarks();
    }



    cout<<"\n--- Grade Results ---\n";

    for(i=0;i<n;i++)
    {
        s[i]->showGrade();
        cout<<endl;
    }



    for(i=0;i<n;i++)
    {
        delete s[i];
    }



    return 0;
}


// Name : Helly Parmar
// ID : 25CE069
