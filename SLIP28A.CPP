

a) Write a C++ program to read array of 'n' integers from user and display it in reverse order. (Use Dynamic memory allocation)
[Marks 15]          


#include <iostream.h>
#include <conio.h>

int main() {
    clrscr();  // Clear the screen
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    // Allocate memory dynamically
    int *arr = new int[n];

    // Check if memory allocation failed
    if (!arr) {
        cout << "Memory allocation failed!";
        return 1;
    }

    cout << "Enter " << n << " integers:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Display the array in reverse order
    cout << "Array in reverse order:" << endl;
    for (int i = n - 1; i >= 0; i--) {
        cout << arr[i] << " ";
    }

    // Free the dynamically allocated memory
    delete[] arr;
    getch();  // Wait for a key press
    return 0;
}
