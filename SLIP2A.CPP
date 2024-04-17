a) Write a C++ program to find volume of cylinder, cone and sphere. (Use function overloading).
[Marks 15]

#include <iostream.h>
#include <conio.h>

// Define the value of pi globally
double PI = 3.14159265358979323846;

// Function to calculate the volume of a cylinder
// Volume of cylinder = π * r^2 * h
double volume(double radius, double height) {
    return PI * radius * radius * height;
}

// Function to calculate the volume of a cone
// Volume of cone = 1/3 * π * r^2 * h
double volume(double radius, double height, int isCone) {
    return (1.0 / 3.0) * PI * radius * radius * height;
}

// Function to calculate the volume of a sphere
// Volume of sphere = 4/3 * π * r^3
double volume(double radius) {
    double radiusCubed = radius * radius * radius; // Manually calculate r^3
    return (4.0 / 3.0) * PI * radiusCubed;
}

int main() {
    clrscr();
    double radius, height;
    cout << "Enter the radius and height for cylinder: ";
    cin >> radius >> height;
    cout << "Volume of the cylinder is: " << volume(radius, height) << endl;

    cout << "Enter the radius and height for cone: ";
    cin >> radius >> height;
    cout << "Volume of the cone is: " << volume(radius, height, 1) << endl;

    cout << "Enter the radius for sphere: ";
    cin >> radius;
    cout << "Volume of the sphere is: " << volume(radius) << endl;

    getch();
    return 0;
}
