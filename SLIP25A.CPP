#include <iostream.h>
#include <conio.h>
#include<stdlib.h>

// Inline function to calculate mean of three numbers
inline float calculateMean(int a, int b, int c) {
    return (a + b + c) / 3.0;
}

// Inline function to calculate median of three numbers
inline int calculateMedian(int a, int b, int c) {
    if ((a >= b && a <= c) || (a >= c && a <= b))
        return a;
    else if ((b >= a && b <= c) || (b >= c && b <= a))
        return b;
    else
        return c;
}

// Inline function to calculate mode of three numbers
// For three numbers, mode might not be a meaningful statistic if all numbers are different
inline int calculateMode(int a, int b, int c) {
    if (a == b || a == c) return a;
    else if (b == c) return b;
    return -1; // Returning -1 if there is no mode
}

int main() {
    clrscr();
    int x, y, z;
    cout << "Enter three integer numbers: ";
    cin >> x >> y >> z;

    float mean = calculateMean(x, y, z);
    int median = calculateMedian(x, y, z);
    int mode = calculateMode(x, y, z);

    cout << "Mean: " << mean << "\n";
    cout << "Median: " << median << "\n";
    cout << "Mode: " << (mode == -1 ? "No mode" : itoa(mode)) << "\n";

    getch();
    return 0;
}
