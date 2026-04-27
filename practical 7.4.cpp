#include <iostream>
#include <vector>
using namespace std;

// --------------------------
// Base Class
// --------------------------
class Shape {

public:
    // Virtual function
    virtual void Area() {
        cout << "Area function of Shape\n";
    }

    // Virtual destructor (good practice)
    virtual ~Shape() {}
};

// --------------------------
// Rectangle Class
// --------------------------
class Rectangle : public Shape {

private:
    float length;
    float width;

public:

    // Constructor
    Rectangle(float l, float w) {
        length = l;
        width = w;
    }

    // Override Area()
    void Area() override {

        float area = length * width;

        cout << "Rectangle Area = "
             << area << endl;
    }
};

// --------------------------
// Circle Class
// --------------------------
class Circle : public Shape {

private:
    float radius;

public:

    // Constructor
    Circle(float r) {
        radius = r;
    }

    // Override Area()
    void Area() override {

        float area = 3.1416 * radius * radius;

        cout << "Circle Area = "
             << area << endl;
    }
};

// --------------------------
// MAIN FUNCTION
// --------------------------
int main() {

    cout << "=== Polymorphism Area System ===\n";

    // --------------------------
    // Static Storage (Array)
    // --------------------------
    Shape* staticShapes[2];

    staticShapes[0] = new Rectangle(5, 4);
    staticShapes[1] = new Circle(3);

    cout << "\nStatic Collection:\n";

    for (int i = 0; i < 2; i++) {
        staticShapes[i]->Area();
    }

    // --------------------------
    // Dynamic Storage (Vector)
    // --------------------------
    vector<Shape*> dynamicShapes;

    dynamicShapes.push_back(new Rectangle(6, 2));
    dynamicShapes.push_back(new Circle(4));
    dynamicShapes.push_back(new Rectangle(3, 3));

    cout << "\nDynamic Collection:\n";

    for (size_t i = 0; i < dynamicShapes.size(); i++) {
        dynamicShapes[i]->Area();
    }

    // --------------------------
    // Memory Cleanup
    // --------------------------
    for (int i = 0; i < 2; i++) {
        delete staticShapes[i];
    }

    for (size_t i = 0; i < dynamicShapes.size(); i++) {
        delete dynamicShapes[i];
    }

    return 0;
}
