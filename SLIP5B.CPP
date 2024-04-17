b) Create a C++ base class Shape. Derive three different classes Circle, Sphere and Cylinder from shape class. Write a C++ program to calculate area of Circle, Sphere and Cylinder. (Use pure virtual function).
[Marks 25]

#include <iostream.h>
#include <math.h> // Included for potential use of math functions
#include<conio.h>
const double PI = 3.14;

class Shape {
public:
    virtual double area() = 0;  // Removed const qualifier
    virtual ~Shape() {}
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() {
	return PI * radius * radius;
    }
};

class Sphere : public Shape {
private:
    double radius;
public:
    Sphere(double r) : radius(r) {}
    double area() {
	return 4 * PI * radius * radius;
    }
};

class Cylinder : public Shape {
private:
    double radius;
    double height;
public:
    Cylinder(double r, double h) : radius(r), height(h) {}
    double area() {
	return 2 * PI * radius * (radius + height);
    }
};

void printArea(Shape& shape) {  // Removed const from the parameter type
    cout << "Area: " << shape.area() << endl;
}

void main() {
    Circle circle(5.0);
    Sphere sphere(4.0);
    Cylinder cylinder(3.0, 7.0);

    cout << "Circle ";
    printArea(circle);

    cout << "Sphere ";
    printArea(sphere);

    cout << "Cylinder ";
    printArea(cylinder);
    getch();
}
