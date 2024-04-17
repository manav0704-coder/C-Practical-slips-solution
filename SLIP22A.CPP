#include <iostream.h>
#include <conio.h>

// Template function to calculate the square of a number
template <class T>
T square(T x) {
    return x * x;
}

// Template function to calculate the cube of a number
template <class T>
T cube(T x) {
    return x * x * x;
}

int main() {
    clrscr();
    int num1 = 5;
    float num2 = 5.5;
    double num3 = 5.25;

    // Display the square and cube of an integer
    cout << "Square of " << num1 << " is " << square(num1) << endl;
    cout << "Cube of " << num1 << " is " << cube(num1) << endl;

    // Display the square and cube of a float
    cout << "Square of " << num2 << " is " << square(num2) << endl;
    cout << "Cube of " << num2 << " is " << cube(num2) << endl;

    // Display the square and cube of a double
    cout << "Square of " << num3 << " is " << square(num3) << endl;
    cout << "Cube of " << num3 << " is " << cube(num3) << endl;

    getch();
    return 0;
}
