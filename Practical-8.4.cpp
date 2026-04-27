#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;



int main()
{
    ifstream file;
    string path;

    string line;
    int sum = 0, count = 0;

    bool opened = false;



    // ---------- FILE OPEN WITH RETRY ----------
    while(!opened)
    {
        try
        {
            cout<<"Enter file path : ";
            cin>>path;

            file.open(path);

            if(!file)
            {
                throw "File Not Found / Cannot Open File";
            }

            opened = true;
        }
        catch(const char* msg)
        {
            cout<<"Error: "<<msg<<endl;
            cout<<"Try again...\n";
        }
    }



    cout<<"\n--- Processing File ---\n";



    // ---------- LINE BY LINE PROCESSING ----------
    while(getline(file, line))
    {
        stringstream ss(line);
        int num;

        if(!(ss >> num))
        {
            cout<<"Corrupted Line Skipped: "<<line<<endl;
            continue;
        }

        sum += num;
        count++;
    }



    file.close();



    cout<<"\n--- Result ---\n";

    if(count > 0)
    {
        cout<<"Sum = "<<sum<<endl;
        cout<<"Average = "<<(float)sum/count<<endl;
    }
    else
    {
        cout<<"No valid data found\n";
    }



    return 0;
}


// Name : Helly Parmar
// ID : 25CE069
