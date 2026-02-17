#include<iostream>
using namespace std;
class item
{
    int id;
    string item_name;
    int price;
    int quantity;
public:
    item()
    {
        id=0;
        item_name="NULL";
        price=0;
        quantity=0;
    }
    item(int i,string name,int p,int q)
    {
        id=i;
        item_name=name;
        price=p;
        quantity=q;
    }
    void add()
    {
        int q;
        cout<<"how much quantity you want to add: ";
        cin>>q;
        quantity+=q;
    }
    void sell()
    {
        int q;
        cout<<"How much quantity you want: ";
        cin>>q;
        if(quantity>=q)
        {
            quantity-=q;
        }
        else
        {
            cout<<"Insufficient Quantity";
        }
    }
    void display()
    {
        cout<<"id is : "<<id<<endl<<"Item name is : "<<item_name<<endl<<"price of the item (single piece)"<<price<<endl;
    }
};
int main()
{
    int n,i,p,q,choice;
    string name;
    cout<<"Enter number of items you want to add: ";
    cin>>n;
    fflush(stdin);
    item a[n];
    for(i=0;i<n;i++)
    {
        cout<<"Enter name of the item: ";
        cin>>name;
        cout<<"Enter price(single piece) of the item: ";
        cin>>p;
        cout<<"Enter Quantity you want to add: ";
        cin>>q;
        a[i]=item(i+1,name,p,q);
    }
    do
    {
        cout<<"1-Add data"<<endl<<"2-Sell data"<<endl<<"3-Display data"<<endl<<"4-exit"<<endl<<"Enter your choice: ";
        cin>>choice;
        int id;
        cout<<"Enter id of the item";
        cin>>id;
        id=id-1;
        if(id<=0||id>n)
        {
            cout<<"Invalid id";
            continue;
        }
        switch(choice)
        {
        case 1:
          a[id].add();
        break;
        case 2:
            a[id].sell();
            break;
        case 3:
            a[id].display();
            break;
        case 4:
            cout<<"Thank you for visiting";
            return 0;
        default:
            cout<<"Enter valid choice";
        }
    }
    while(choice!=4);
    return 0;
}
