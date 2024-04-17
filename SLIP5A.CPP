#include <iostream.h>

class Point {
    int x, y;

public:
    // Function to set the values of x and y coordinates
    void setPoint(int a, int b) {
	x = a;
	y = b;
    }

    // Function to display coordinates of a point in format (x, y)
    void showPoint() {
	cout << "(" << x << ", " << y << ")" << endl;
    }
};

int main() {
    Point p;  // Create an instance of Point
    p.setPoint(3, 8); // Setting the coordinates
    p.showPoint(); // Displaying the coordinates

    return 0;
}
