#include<iostream>
using namespace std;

class DynamicArray
{
private:

    int *arr;
    int size;

public:

    DynamicArray()
    {
        arr=NULL;
        size=0;
    }



    void insert(int value)
    {
        int *newArr;

        newArr=new int[size+1];

        for(int i=0;i<size;i++)
        {
            newArr[i]=arr[i];
        }

        newArr[size]=value;

        delete[] arr;

        arr=newArr;

        size++;

        cout<<"Element inserted successfully\n";
    }




    void deleteAt(int position)
    {
        if(size==0)
        {
            cout<<"Array is empty\n";
            return;
        }

        if(position<0 || position>=size)
        {
            cout<<"Invalid Position\n";
            return;
        }


        int *newArr;

        newArr=new int[size-1];


        for(int i=0,j=0;i<size;i++)
        {
            if(i!=position)
            {
                newArr[j]=arr[i];
                j++;
            }
        }


        delete[] arr;

        arr=newArr;

        size--;

        cout<<"Element deleted successfully\n";
    }




    void display()
    {
        if(size==0)
        {
            cout<<"Array is empty\n";
            return;
        }

        cout<<"Array Elements : ";

        for(int i=0;i<size;i++)
        {
            cout<<arr[i]<<" ";
        }

        cout<<endl;
    }




    ~DynamicArray()
    {
        delete[] arr;
    }

};



int main()
{
    DynamicArray da;

    int choice;
    int value;
    int position;


M:

    cout<<"\n1.Insert";
    cout<<"\n2.Delete";
    cout<<"\n3.Display";
    cout<<"\n4.Exit";

    cout<<"\nEnter Choice : ";
    cin>>choice;



    switch(choice)
    {

        case 1:

            cout<<"Enter value to insert : ";
            cin>>value;

            da.insert(value);

            goto M;



        case 2:

            cout<<"Enter position to delete (0-based) : ";
            cin>>position;

            da.deleteAt(position);

            goto M;



        case 3:

            da.display();

            goto M;



        case 4:
            break;



        default:

            cout<<"Invalid Choice\n";
            goto M;
    }



    return 0;
}


// Name : Helly Parmar
// ID : 25CE069
