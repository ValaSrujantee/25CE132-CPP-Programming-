#include <iostream>
using namespace std;

// Recursive function to find super digit
int superDigit(int n)
{
    // Base case: single digit
    if (n < 10)
        return n;

    int sum = 0;

    // Find sum of digits
    while (n > 0)
    {
        sum = sum + (n % 10);
        n = n / 10;
    }

    // Recursive call
    return superDigit(sum);
}

int main()
{
    int n, k;
    int sum = 0;

    cout << "Enter number: ";
    cin >> n;

    cout << "Enter value of k: ";
    cin >> k;

    // Multiply sum by k
    while (n > 0)
    {
        sum = sum + (n % 10);
        n = n / 10;
    }

    sum = sum * k;

    // Find super digit
    cout << "Super Digit = " << superDigit(sum);

    return 0;
}
