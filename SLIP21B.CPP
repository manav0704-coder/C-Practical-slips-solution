
b) Create a C++ class for a two dimensional points. Write necessary member functions to accept & display the point object. Overload the following operators:
Operator
Example
Purpose
+ (Binary)
P3-P1+P2
Adds coordinates of point pl and p2.
- (Unary)
-P1
Negates coordinates of point pl.
*(Binary)
P2=P1*n
Multiply coordinates of point p1 by constant 'n'
marks[25]

#include <iostream.h>
#include <conio.h>

class Point {
private:
    int x, y;

public:
    // Default constructor
    Point() : x(0), y(0) {}

    // Constructor to initialize coordinates
    Point(int px, int py) : x(px), y(py) {}

    // Function to accept point coordinates
    void accept() {
        cout << "Enter x coordinate: ";
        cin >> x;
        cout << "Enter y coordinate: ";
        cin >> y;
    }

    // Function to display point coordinates
    void display() const {
        cout << "(" << x << ", " << y << ")" << endl;
    }

    // Operator overloading for adding two points
    Point operator+(const Point& p) {
        return Point(x + p.x, y + p.y);
    }

    // Operator overloading for negating coordinates
    Point operator-() {
        return Point(-x, -y);
    }

    // Operator overloading for multiplying coordinates by a constant
    Point operator*(int n) {
        return Point(x * n, y * n);
    }
};

int main() {
    clrscr();
    Point P1, P2, P3;

    cout << "Enter first point P1:" << endl;
    P1.accept();

    cout << "Enter second point P2:" << endl;
    P2.accept();

    P3 = P1 + P2;
    cout << "After adding P1 and P2: ";
    P3.display();

    Point negP1 = -P1;
    cout << "Negating P1: ";
    negP1.display();

    int scalar = 3;
    Point P1Scaled = P1 * scalar;
    cout << "P1 multiplied by " << scalar << ": ";
    P1Scaled.display();

    getch();
    return 0;
}
