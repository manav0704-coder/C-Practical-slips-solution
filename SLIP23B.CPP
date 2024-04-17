b) Create a C++ class ComplexNumber with data members real and imaginary. Write necessary functions:
i. To accept Complex Number using constructor.
ii. To display Complex Number in format [x + iy].
iii. To add two Complex Numbers by using friend function.

#include <iostream.h>
#include <conio.h>

class ComplexNumber {
private:
    float real;
    float imaginary;

public:
    // Constructor to initialize real and imaginary parts
    ComplexNumber(float r = 0.0, float i = 0.0) : real(r), imaginary(i) {}

    // Display complex number in the format [x + iy]
    void display() const {
        if (imaginary >= 0)
            cout << "[" << real << " + " << imaginary << "i]";
        else
            cout << "[" << real << " - " << -imaginary << "i]";
    }

    // Friend function to add two complex numbers
    friend ComplexNumber add(const ComplexNumber& c1, const ComplexNumber& c2);
};

// Function to add two complex numbers
ComplexNumber add(const ComplexNumber& c1, const ComplexNumber& c2) {
    ComplexNumber temp;
    temp.real = c1.real + c2.real;
    temp.imaginary = c1.imaginary + c2.imaginary;
    return temp;
}

int main() {
    clrscr();

    // Create two complex numbers
    ComplexNumber c1(3.5, 2.5), c2(1.5, -4.5);

    // Display both complex numbers
    cout << "Complex Number 1: ";
    c1.display();
    cout << "\nComplex Number 2: ";
    c2.display();

    // Add the complex numbers
    ComplexNumber c3 = add(c1, c2);

    // Display the result of the addition
    cout << "\nSum of Complex Number 1 and 2: ";
    c3.display();

    getch();
    return 0;
}
