
b) Write a C++ program to overload 'display_str' function as follows:
i. void display_str(char *) - Display a string in double quotes.
ii. void display_str (int n, char *)- Display first n characters from a given string.
iii. void display_str (int m, int n,char *)- Display substring of a given string from position m to n.

#include <iostream.h>
#include <conio.h>
#include <string.h>

// Function to display a string in double quotes
void display_str(char *str) {
    cout << "\"" << str << "\"" << endl;
}

// Function to display the first n characters of a string
void display_str(int n, char *str) {
    cout << "\"";
    for (int i = 0; i < n && str[i] != '\0'; i++) {
        cout << str[i];
    }
    cout << "\"" << endl;
}

// Function to display a substring from position m to n
void display_str(int m, int n, char *str) {
    int len = strlen(str);
    cout << "\"";
    for (int i = m; i <= n && i < len; i++) {
        cout << str[i];
    }
    cout << "\"" << endl;
}

int main() {
    clrscr();
    char str[] = "Hello, world!";
    
    // Display the entire string
    display_str(str);
    
    // Display the first 5 characters of the string
    display_str(5, str);
    
    // Display a substring from position 3 to 7
    display_str(3, 7, str);
    
    getch();
    return 0;
}
