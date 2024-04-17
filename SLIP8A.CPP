#include <iostream.h>
#include <conio.h>

class Number {
public:
    static int cnt; // Declare static member to keep track of Display calls

    void Display() {
        cnt++; // Increment on each call to Display
        cout << "Display has been called " << cnt << " times." << endl;
    }
};

int Number::cnt = 0; // Initialize static member

void main() {
    clrscr();
    Number a, b, c; // Create multiple instances

    a.Display(); // Call Display using object a
    b.Display(); // Call Display using object b
    c.Display(); // Call Display using object c

    getch();
}
