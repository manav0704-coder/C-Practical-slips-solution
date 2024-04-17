#include <iostream.h>
#include <conio.h>
#include <string.h> // for strlen function

class StringManipulator {
    char str[50]; // data member to hold the string

public:
    // Constructor to initialize the string
    StringManipulator(const char* s) {
        strcpy(str, s); // copy the provided string into str
    }

    // Function to replace occurrences of ch1 with ch2 and return the count of replacements
    int replace(char ch1, char ch2 = '*') {
        int count = 0;
        for (int i = 0; i < strlen(str); i++) {
            if (str[i] == ch1) {
                str[i] = ch2;
                count++;
            }
        }
        return count;
    }

    // Function to display the string
    void display() const {
        cout << "Modified String: " << str << endl;
    }
};

void main() {
    clrscr();
    char initialChar, replacementChar;
    cout << "Enter a string (up to 49 characters): ";
    char input[50];
    cin.getline(input, 50);

    StringManipulator manip(input);

    cout << "Enter character to replace: ";
    cin >> initialChar;

    cout << "Enter replacement character (press Enter for default '*'): ";
    cin >> replacementChar;

    int replacements = manip.replace(initialChar, replacementChar);
    cout << "Number of replacements made: " << replacements << endl;

    manip.display();

    getch(); // Wait for user input before closing
}
