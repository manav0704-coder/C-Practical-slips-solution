#include <iostream.h>
#include <conio.h>

// Function to find average of three integers
double average(int a, int b, int c) {
    return (a + b + c) / 3.0; // Ensure floating point division
}

// Function to find average of three floats
double average(float a, float b, float c) {
    return (a + b + c) / 3.0;
}

int main() {
    clrscr();
    int x1 = 10, x2 = 20, x3 = 30;
    float f1 = 10.5, f2 = 20.5, f3 = 30.5;

    // Display averages
    cout << "Average of integers: " << average(x1, x2, x3) << endl;
    cout << "Average of floats: " << average(f1, f2, f3) << endl;

    getch();
    return 0;
}
