a) Write a C++ program to create a class Distance with data members meter and centimeter to represent distance. Write a function Larger() to return the larger of two distances. (Use this pointer)
[Marks 15]

#include <iostream.h>
#include <conio.h>

class Distance {
private:
    int meter;
    int centimeter;

public:
    // Constructor to initialize the distance to 0 if no value is provided
    Distance(int m = 0, int cm = 0) {
        meter = m;
        centimeter = cm;
        normalize();
    }

    void normalize() {
        meter += centimeter / 100;
        centimeter %= 100;
    }

    // Function to accept distance from user
    void accept() {
        cout << "Enter meters: ";
        cin >> meter;
        cout << "Enter centimeters: ";
        cin >> centimeter;
        normalize();
    }

    // Function to display distance
    void display() const {
        cout << meter << " meter(s) and " << centimeter << " centimeter(s)" << endl;
    }

    // Function to find and return the larger distance
    Distance& Larger(Distance &d) {
        int totalCm1 = this->meter * 100 + this->centimeter;
        int totalCm2 = d.meter * 100 + d.centimeter;
        if (totalCm1 > totalCm2) {
            return *this;
        } else {
            return d;
        }
    }
};

int main() {
    clrscr();
    Distance d1, d2, larger;

    cout << "Enter the first distance:\n";
    d1.accept();
    cout << "Enter the second distance:\n";
    d2.accept();

    cout << "First distance: ";
    d1.display();
    cout << "Second distance: ";
    d2.display();

    larger = d1.Larger(d2);
    cout << "The larger distance is: ";
    larger.display();

    getch();
    return 0;
}
