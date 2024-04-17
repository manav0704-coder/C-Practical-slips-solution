#include <iostream.h>
#include <conio.h>

class Weight {
private:
    int kilogram;
    int gram;

public:
    // Constructor to initialize weight to 0 if no values are provided
    Weight() : kilogram(0), gram(0) {}

    // Function to accept weight from user
    void accept() {
        cout << "Enter weight in kilograms: ";
        cin >> kilogram;
        cout << "Enter weight in grams: ";
        cin >> gram;
        normalize();
    }

    // Normalize the weight so that grams are less than 1000
    void normalize() {
        kilogram += gram / 1000;
        gram %= 1000;
    }

    // Function to display weight in kilogram and gram format
    void display() const {
        cout << kilogram << " kg " << gram << " g" << endl;
    }

    // Overload += operator to add two weights
    void operator += (const Weight& w) {
        kilogram += w.kilogram;
        gram += w.gram;
        normalize();
    }

    // Overload == operator to check equality of two weights
    bool operator == (const Weight& w) const {
        return (kilogram == w.kilogram && gram == w.gram);
    }
};

int main() {
    clrscr();
    Weight w1, w2;

    cout << "Enter first weight:" << endl;
    w1.accept();
    cout << "Enter second weight:" << endl;
    w2.accept();

    cout << "\nFirst weight: ";
    w1.display();
    cout << "Second weight: ";
    w2.display();

    w1 += w2;
    cout << "\nAfter adding second weight to first weight: ";
    w1.display();

    if (w1 == w2)
        cout << "Weights are equal." << endl;
    else
        cout << "Weights are not equal." << endl;

    getch();
    return 0;
}
