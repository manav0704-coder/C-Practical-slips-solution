#include <iostream.h>
#include <conio.h>

class Circle {
private:
    float radius;

public:
    // Constructor to initialize the radius
    void setRadius(float r) {
        radius = r;
    }

    // Inline function to calculate diameter of the circle
    inline float diameter() {
        return 2 * radius;
    }

    // Inline function to calculate circumference of the circle
    inline float circumference() {
        return 2 * 3.14159 * radius;  // Pi is approximated as 3.14159
    }

    // Inline function to calculate area of the circle
    inline float area() {
        return 3.14159 * radius * radius; // Pi is approximated as 3.14159
    }
};

int main() {
    clrscr();
    Circle c;
    float r;

    cout << "Enter the radius of the circle: ";
    cin >> r;

    c.setRadius(r);
    clrscr();

    cout << "Diameter of the circle: " << c.diameter() << endl;
    cout << "Circumference of the circle: " << c.circumference() << endl;
    cout << "Area of the circle: " << c.area() << endl;

    getch();
    return 0;
}
