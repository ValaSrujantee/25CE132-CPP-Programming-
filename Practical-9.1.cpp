#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



void display(vector<int> v)
{
    cout<<"Vector : ";
    for(auto it = v.begin(); it != v.end(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}



int main()
{
    vector<int> v;
    int n, val;

    cout<<"Enter number of elements : ";
    cin>>n;

    cout<<"Enter elements : ";
    for(int i = 0; i < n; i++)
    {
        cin>>val;
        v.push_back(val);
    }



    cout<<"\n--- Original Vector ---\n";
    display(v);



    // ---------- METHOD 1: STL reverse ----------
    vector<int> v1 = v;

    reverse(v1.begin(), v1.end());

    cout<<"\n--- Using std::reverse() ---\n";
    display(v1);



    // ---------- METHOD 2: Manual iterator reversal ----------
    vector<int> v2 = v;

    auto start = v2.begin();
    auto end = v2.end() - 1;

    while(start < end)
    {
        swap(*start, *end);
        start++;
        end--;
    }

    cout<<"\n--- Manual Iterator Reversal ---\n";
    display(v2);



    return 0;
}


// Name : Helly Parmar
// ID : 25CE069
