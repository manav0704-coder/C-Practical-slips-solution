b) Create a C++ class Cuboid with data members length, breadth, and height. Write necessary member functions for the following:
i. void setvalues(float, float, float) to set values of data members.
ii. void getvalues() to display values of data members.
iii. float volume() to calculate and return the volume of cuboid.
iv. float surface_area() to calculate and return the surface area of cuboid.
(Use Inline function)
[Marks 25]

#include <iostream.h>
#include <conio.h>

class Cuboid {
private:
    float length, breadth, height;

public:
    // Inline function to set values of data members
    void setvalues(float l, float b, float h) {
        length = l;
        breadth = b;
        height = h;
    }

    // Inline function to display values of data members
    void getvalues() {
        cout << "Length: " << length << endl;
        cout << "Breadth: " << breadth << endl;
        cout << "Height: " << height << endl;
    }

    // Inline function to calculate and return the volume of cuboid
    float volume() {
        return length * breadth * height;
    }

    // Inline function to calculate and return the surface area of the cuboid
    float surface_area() {
        return 2 * (length * breadth + breadth * height + height * length);
    }
};

int main() {
    clrscr();
    Cuboid c;

    float l, b, h;
    cout << "Enter length, breadth, and height of the cuboid: ";
    cin >> l >> b >> h;

    c.setvalues(l, b, h);
    clrscr();

    cout << "Cuboid dimensions:" << endl;
    c.getvalues();

    cout << "Volume of Cuboid: " << c.volume() << endl;
    cout << "Surface Area of Cuboid: " << c.surface_area() << endl;

    getch();
    return 0;
}
