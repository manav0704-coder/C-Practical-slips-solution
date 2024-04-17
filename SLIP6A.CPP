#include <iostream.h>  // Use <iostream.h> instead of <iostream>

class Rectangle;  

class Square {
private:
    double side;  // Side length of the square
    
public:
    Square(double s) : side(s) {}  // Constructor
    
    double area() const {
        return side * side;
    }

    // Friend function declaration
    friend void compareArea(const Square&, const Rectangle&);
};

class Rectangle {
private:
    double width, height;  // Dimensions of the rectangle
    
public:
    Rectangle(double w, double h) : width(w), height(h) {}  
    
    double area() const {
        return width * height;
    }

    // Friend function declaration
    friend void compareArea(const Square&, const Rectangle&);
};

// Friend function to compare the area of a square and a rectangle
void compareArea(const Square& sq, const Rectangle& rec) {
    double areaSq = sq.area();
    double areaRec = rec.area();
    if (areaSq > areaRec) {
        cout << "Square with area " << areaSq << " is larger than Rectangle with area " << areaRec << "." << endl;
    } else if (areaSq < areaRec) {
        cout << "Rectangle with area " << areaRec << " is larger than Square with area " << areaSq << "." << endl;
    } else {
        cout << "Both shapes have the same area: " << areaSq << "." << endl;
    }
}

void main() {
    Square s(5);            
    Rectangle r(4, 6);      

    compareArea(s, r);
}
