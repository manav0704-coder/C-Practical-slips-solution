b) Create a C++ class MyString with data members a character pointer and str_length. (Use new and delete operator). Write a C++ program using operator overloading to perform following operation:
i. ! To reverse the case of each alphabet from a given string.
ii. < To compare length of two strings.
111. + To add constant 'n' to each alphabet of a string.
[Marks 25]

#include <iostream.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

class MyString {
private:
    char *str;
    int str_length;

public:
    MyString() : str(NULL), str_length(0) {}  // Default constructor

    MyString(const char *s) {  // Parameterized constructor
        str_length = strlen(s);
        str = new char[str_length + 1];
        strcpy(str, s);
    }

    ~MyString() {  // Destructor
        delete[] str;
    }

    // Reverse the case of each alphabet in the string
    void operator!() {
        for (int i = 0; i < str_length; i++) {
            if (islower(str[i]))
                str[i] = toupper(str[i]);
            else if (isupper(str[i]))
                str[i] = tolower(str[i]);
        }
    }

    // Compare length of two strings
    int operator<(MyString &s) {
        return str_length < s.str_length;  // 1 if true, 0 if false
    }

    // Add 'n' to each alphabet in the string
    MyString operator+(int n) {
        MyString temp = *this; // Create a copy of the current object
        for (int i = 0; i < str_length; i++) {
            if (isalpha(temp.str[i]))
                temp.str[i] += n;
        }
        return temp;
    }

    // To display the string
    void display() {
        cout << str << endl;
    }
};

int main() {
    clrscr();
    MyString s1("Hello World");
    MyString s2("Hello");
    MyString s3;

    cout << "Original string s1: ";
    s1.display();

    // Reversing the case
    !s1;
    cout << "After reversing the case: ";
    s1.display();

    // Comparing length
    if (s1 < s2)
        cout << "s1 is shorter than s2\n";
    else
        cout << "s1 is not shorter than s2\n";

    // Adding '1' to each alphabet
    s3 = s1 + 1;
    cout << "s1 after adding '1' to each alphabet: ";
    s3.display();

    getch();
    return 0;
}
