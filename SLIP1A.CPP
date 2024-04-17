
Q1 write a c++ programe to find maximum and minimum of two integer numbers using inline function and conditional operator ?


#include <iostream>

// Inline function to find maximum of two numbers
inline int max(int a, int b) {
    return (a > b) ? a : b;
}

// Inline function to find minimum of two numbers
inline int min(int a, int b) {
    return (a < b) ? a : b;
}

int main() {
    int x, y;
    std::cout << "Enter two integers: ";
    std::cin >> x >> y;

    // Call the inline functions and display results
    std::cout << "Maximum of " << x << " and " << y << " is " << max(x, y) << std::endl;
    std::cout << "Minimum of " << x << " and " << y << " is " << min(x, y) << std::endl;

    return 0;
}
