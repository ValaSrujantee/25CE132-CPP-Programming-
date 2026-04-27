#include<iostream>
#include<map>
#include<vector>
using namespace std;



int main()
{
    map<string, vector<string>> directory;

    int ch;
    string folder, file;

M:

    cout<<"\n1.Add Folder";
    cout<<"\n2.Add File to Folder";
    cout<<"\n3.Display Directory";
    cout<<"\n4.Exit";

    cout<<"\nEnter choice : ";
    cin>>ch;



    switch(ch)
    {

        case 1:
        {
            cout<<"Enter folder name : ";
            cin>>folder;

            directory[folder];   // creates empty folder

            cout<<"Folder added successfully\n";

            goto M;
        }



        case 2:
        {
            cout<<"Enter folder name : ";
            cin>>folder;

            if(directory.find(folder) == directory.end())
            {
                cout<<"Folder not found\n";
                goto M;
            }

            cout<<"Enter file name : ";
            cin>>file;

            directory[folder].push_back(file);

            cout<<"File added successfully\n";

            goto M;
        }



        case 3:
        {
            cout<<"\n--- Directory Structure ---\n";

            for(auto it = directory.begin(); it != directory.end(); it++)
            {
                cout<<"Folder: "<<it->first<<endl;

                vector<string> files = it->second;

                for(int i = 0; i < files.size(); i++)
                {
                    cout<<"   - "<<files[i]<<endl;
                }
            }

            goto M;
        }



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
