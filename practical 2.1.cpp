#include<iostream>
using namespace std;
class Rectangle
{
    float length,width;
public:
    void setDimensions(float,float);
    void updateDimensions(float,float);
    float area();
    float perimeter();
    void display(int);
};

void Rectangle::setDimensions(float l, float w)
{
    length = l;
    width = w;
}
void Rectangle::updateDimensions(float l, float w)
{
    length = l;
    width = w;
}
float Rectangle:: area()
{
    return length * width;
}

float Rectangle:: perimeter()
{
    return 2 * (length + width);
}
 void Rectangle::display(int index) {
        cout << "\nRectangle " << index + 1 << endl;
        cout << "Length    : " << length << endl;
        cout << "Width     : " << width << endl;
        cout << "Area      : " << area() << endl;
        cout << "Perimeter : " << perimeter() << endl;
int main()
{
    int choice;
    int count=0;

    Rectangle rect[10];
    cout << "\n----- Rectangle Management System -----";
    cout << "\n1. Add Rectangle";
    cout << "\n2. Update Rectangle";
    cout << "\n3. Display All Rectangles";
    cout << "\n4. Exit";
    cout << "\nEnter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        if (count < 10)
        {
            float l, w;
            cout << "Enter length: ";
            cin >> l;
            cout << "Enter width: ";
            cin >> w;
            rect[count].setDimensions(l, w);
            count++;
            cout << "Rectangle added successfully!\n";
        }
        else
        {
            cout << "Storage full! Cannot add more rectangles.\n";
        }
    case 2:

        int index;
        float l, w;
        cout << "Enter rectangle number to update: ";
        cin >> index;

        if (index > 0 && index <= count)
        {
            cout << "Enter new length: ";
            cin >> l;
            cout << "Enter new width: ";
            cin >> w;
            rect[index - 1].updateDimensions(l, w);
            cout << "Rectangle updated successfully!\n";
        }
        else
        {
            cout << "Invalid rectangle number!\n";
        }


    case 3:

        if (count == 0)
        {
            cout << "No rectangles available.\n";
        }
        else
        {
            for (int i = 0; i < count; i++)
            {
                rect[i].display(i);
            }
        }


    case 4:

        cout << "Exiting program...\n";

    default:

        cout << "Invalid choice!\n";

    }
    return 0;
}





