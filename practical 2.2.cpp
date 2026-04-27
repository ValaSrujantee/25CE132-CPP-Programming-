#include<iostream>
#include<string.h>
using namespace std;
class student
{
    int roll_no;
    string name;
    int marks1,marks2,marks3;
    float avg;
public:
    student()
    {
        int roll = 0;
        int m1=0,m2=0,m3=0;
    }

    student(int,string,int,int,int);
    void display();
    float average(int,int,int);
};
student::student(int r,string n,int m1,int m2,int m3)
{
    if(r<=0||m1<=0||m2<=0||m3<=0)
    {
        cout<<"Invalid input";

    }
    else
    {
        roll_no=r;
        name=n;
        marks1=m1;
        marks2=m2;
        marks3=m3;
    }
}
float student::average(int marks1,int marks2,int marks3)
{
    return (marks1+marks2+marks3)/3.0;
}
void student::display()
{

    cout<<"Student Roll number is : "<<roll_no<<endl;
    cout<<"Student Name is : "<<name<<endl;
    cout<<"Student average is : "<<average(marks1,marks2,marks3)<<endl<<endl;
}
int main()
{
    int n,m1,m2,m3,r,i;
    string na;
    cout<<"Enter number of students you want to store marks for: ";
    cin>>n;
    student st;
    student s[n];
    for(i=0; i<n; i++)
    {
        cout<<"Enter roll number of student "<<i+1<<" : ";
        cin>>r;
        fflush(stdin);
        cout<<"Enter student name :";
l:
        getline(cin, na);
        if(na == "" )
            goto l;

        cout<<"Enter marks of subject "<<i+1<<" : ";
        cin>>m1;
        cout<<"Enter marks of subject "<<i+2<<" : ";
        cin>>m2;
        cout<<"Enter marks of subject "<<i+3<<" : ";
        cin>>m3;
        s[i]=student(r,na,m1,m2,m3);
        fflush(stdin);
    }
    cout<<endl<<endl<<"STUDENT RESULT"<<endl<<endl;
    st.display();
    for(i=0; i<n; i++)
    {
        s[i].display();
    }


    return 0;
}
