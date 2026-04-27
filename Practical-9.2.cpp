#include<iostream>
#include<map>
#include<sstream>
using namespace std;

int main()
{
    string sentence;
    map<string, int> freq;

    cout<<"Enter a sentence : ";
    getline(cin, sentence);

    stringstream ss(sentence);
    string word;



    // Extract words and count frequency
    while(ss >> word)
    {
        freq[word]++;
    }



    cout<<"\n--- Word Frequency ---\n";

    for(auto it = freq.begin(); it != freq.end(); it++)
    {
        cout<<it->first<<" : "<<it->second<<endl;
    }



    return 0;
}


// Name : Helly Parmar
// ID : 25CE069
