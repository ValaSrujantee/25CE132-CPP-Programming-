#include <iostream>
#include <fstream>
#include <string>
#include <cctype>   // for isspace()

using namespace std;

int main() {

    ifstream file;        // File input stream
    string line;          // To store each line

    int charCount = 0;        // Counts characters including spaces
    int wordCount = 0;        // Counts words
    int lineCount = 0;        // Counts lines

    // Step 1: Open file
    file.open("input.txt");

    // Step 2: Check if file opened successfully
    if (!file) {
        cout << "Error: File could not be opened!" << endl;
        return 1;
    }

    // Step 3: Read file line by line
    while (getline(file, line)) {

        lineCount++;   // Increase line count

        bool inWord = false;

        // Scan characters in the line
        for (int i = 0; i < line.length(); i++) {

            char ch = line[i];

            // Count characters
            charCount++;

            // Detect word boundaries
            if (!isspace(ch) && !inWord) {
                wordCount++;
                inWord = true;
            }

            if (isspace(ch)) {
                inWord = false;
            }
        }
    }

    // Step 4: Close file
    file.close();

    // Step 5: Display results
    cout << "Total Lines: " << lineCount << endl;
    cout << "Total Words: " << wordCount << endl;
    cout << "Total Characters (including spaces): "
         << charCount << endl;

    return 0;
}
