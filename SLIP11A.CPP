a) Create a C++ class MyArray, which contains single dimensional integer array of a given size. Write a member function to display sum of given array elements. (Use Dynamic Constructor and Destructor)
[Marks 151

#include <iostream.h>
#include <conio.h>

class MyArray {
private:
    int* arr;      // Pointer to the array
    int size;      // Size of the array

public:
    // Dynamic constructor to allocate memory
    MyArray(int sz) {
        size = sz;
        arr = new int[size]; // Allocate memory for the array
        cout << "Enter elements of the array:" << endl;
        for (int i = 0; i < size; i++) {
            cout << "Element " << i + 1 << ": ";
            cin >> arr[i];
        }
    }

    // Destructor to deallocate memory
    ~MyArray() {
        delete[] arr; // Free the allocated memory
        cout << "Memory released." << endl;
    }

    // Function to display the sum of array elements
    void displaySum() {
        int sum = 0;
        for (int i = 0; i < size; i++) {
            sum += arr[i];
        }
        cout << "Sum of array elements: " << sum << endl;
    }
};

int main() {
    clrscr();
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    MyArray myArray(n); // Creating an object of MyArray
    myArray.displaySum(); // Displaying the sum of elements
    getch();
    return 0;
}
