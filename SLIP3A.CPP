a) Write a C++ program to interchange values of two integer numbers. (Use call by reference)
[Marks 15]

#include <iostream.h>
#include <conio.h>

// Function to swap two integers using reference
void swap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

void main() {
    clrscr();
    int a, b;

    // User input for two integers
    cout << "Enter two integers:\n";
    cout << "Enter first integer: ";
    cin >> a;
    cout << "Enter second integer: ";
    cin >> b;

    // Displaying values before swapping
    cout << "\nBefore swapping:" << endl;
    cout << "First integer = " << a << ", Second integer = " << b << endl;

    // Calling the swap function
    swap(a, b);

    // Displaying values after swapping
    cout << "\nAfter swapping:" << endl;
    cout << "First integer = " << a << ", Second integer = " << b << endl;

    getch();
}
