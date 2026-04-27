#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    string paragraph;

    cout << "Enter a paragraph:\n";
    getline(cin, paragraph);

    string words[100];
    int count[100] = {0};

    int wordCount = 0;
    string currentWord = "";

    for (int i = 0; i < paragraph.length(); i++) {

        char ch = paragraph[i];

        ch = tolower(ch);

        if (isalnum(ch)) {
            currentWord += ch;
        }
        else {
            if (currentWord != "") {

                bool found = false;

                for (int j = 0; j < wordCount; j++) {
                    if (words[j] == currentWord) {
                        count[j]++;
                        found = true;
                        break;
                    }
                }

                if (!found) {
                    words[wordCount] = currentWord;
                    count[wordCount] = 1;
                    wordCount++;
                }

                currentWord = "";
            }
        }
    }

    if (currentWord != "") {
        bool found = false;

        for (int j = 0; j < wordCount; j++) {
            if (words[j] == currentWord) {
                count[j]++;
                found = true;
                break;
            }
        }

        if (!found) {
            words[wordCount] = currentWord;
            count[wordCount] = 1;
            wordCount++;
        }
    }

    cout << "\nWord Frequencies:\n";

    for (int i = 0; i < wordCount; i++) {
        cout << words[i] << " : " << count[i] << endl;
    }

    return 0;
}
