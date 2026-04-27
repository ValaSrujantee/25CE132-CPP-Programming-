#include<iostream>
#include<set>
#include<vector>
using namespace std;

int main()
{
    set<int> s;
    vector<int> v;

    int n, val;

    cout<<"Enter number of elements : ";
    cin>>n;

    cout<<"Enter elements : ";

    for(int i = 0; i < n; i++)
    {
        cin>>val;
        s.insert(val);
    }



    cout<<"\nUnique Elements : ";

    for(auto it = s.begin(); it != s.end(); it++)
    {
        cout<<*it<<" ";
    }

    cout<<endl;



    for(auto it = s.begin(); it != s.end(); it++)
    {
        v.push_back(*it);
    }



    cout<<"\nVector Elements : ";

    for(int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }

    cout<<endl;



    return 0;
}


// Name : Helly Parmar
// ID : 25CE069
