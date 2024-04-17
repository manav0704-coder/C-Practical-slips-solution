#include <iostream.h>
#include <conio.h>

class Fraction {
private:
    int numerator;
    int denominator;

public:
    // Constructor to initialize the fraction
    Fraction(int n, int d) {
        numerator = n;
        if (d == 0) {
            cout << "Error: Denominator cannot be zero." << endl;
            denominator = 1; // default to 1 to avoid division by zero
        } else {
            denominator = d;
        }
    }

    // Function to calculate and return the sum of two fractions
    Fraction add(Fraction other) {
        int newNumerator = numerator * other.denominator + other.numerator * denominator;
        int newDenominator = denominator * other.denominator;
        return Fraction(newNumerator, newDenominator);
    }

    // Function to reduce the fraction using the greatest common divisor (GCD)
    void reduce() {
        int gcd = findGCD(numerator, denominator);
        numerator /= gcd;
        denominator /= gcd;
    }

    // Helper function to find GCD
    int findGCD(int a, int b) {
        while (b != 0) {
            int t = b;
            b = a % b;
            a = t;
        }
        return a;
    }

    // Function to display the fraction
    void display() {
        cout << numerator << "/" << denominator;
    }
};

int main() {
    clrscr();

    // Create two fractions
    Fraction f1(1, 2); // Represents 1/2
    Fraction f2(3, 4); // Represents 3/4

    // Calculate sum
    Fraction result = f1.add(f2);
    result.reduce(); // Reduce the result to simplest form

    // Display the result
    cout << "Sum of ";
    f1.display();
    cout << " and ";
    f2.display();
    cout << " is ";
    result.display();
    cout << endl;

    getch();
    return 0;
}
