#include <iostream>
using namespace std;

class Point {
private:
    int x;
    int y;

public:
    Point(int xVal = 0, int yVal = 0) {
        x = xVal;
        y = yVal;
    }

    Point& move(int dx, int dy) {
        x = x + dx;
        y = y + dy;
        return *this;
    }

    void display() {
        cout << "Point Coordinates: (" << x << ", " << y << ")" << endl;
    }

    friend void updatePoint(Point *p, int newX, int newY);
};

void updatePoint(Point *p, int newX, int newY) {
    p->x = newX;
    p->y = newY;
}

int main() {
    Point p(2, 3);

    cout << "Initial Position:" << endl;
    p.display();

    p.move(2, 3).move(-1, 4);

    cout << "After Chainable Movement:" << endl;
    p.display();

    updatePoint(&p, 10, 20);

    cout << "After Updating via Pointer:" << endl;
    p.display();

    return 0;
}
