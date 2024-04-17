#include <iostream.h>
#include <conio.h>

class Number {
private:
    int value;

public:
    // Constructor to initialize the value
    Number(int val = 0) : value(val) {}

    // Pre-increment operator
    Number& operator++() {
        value++;  // Increment this object's value
        return *this;  // Return this object
    }

    // Post-increment operator
    Number operator++(int) {
        Number temp = *this;  // Create a temporary object with the current state
        value++;  // Increment this object's value
        return temp;  // Return the unincremented state
    }

    // Function to display the value
    void display() {
        cout << "Current Value: " << value << endl;
    }
};

int main() {
    clrscr();  // Clear the screen
    Number num(10);

    cout << "Original number: ";
    num.display();

    ++num;  // Using pre-increment
    cout << "After pre-increment: ";
    num.display();

    num++;  // Using post-increment
    cout << "After post-increment: ";
    num.display();

    getch();  // Wait for user input
    return 0;
}
