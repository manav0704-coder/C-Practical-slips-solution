#include <iostream.h>
#include <conio.h>
#include <string.h>

class MyString {
private:
    char *str;

public:
    // Constructor
    MyString(const char *s = "") {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }

    // Copy Constructor
    MyString(const MyString& source) {
        str = new char[strlen(source.str) + 1];
        strcpy(str, source.str);
    }

    // Destructor
    ~MyString() {
        delete[] str;
    }

    // Overloaded '+' operator for string concatenation
    MyString operator+(const MyString& rhs) {
        char *temp = new char[strlen(str) + strlen(rhs.str) + 1];
        strcpy(temp, str);
        strcat(temp, rhs.str);
        MyString newStr(temp);
        delete[] temp;
        return newStr;
    }

    // Function to display the string
    void display() {
        cout << str << endl;
    }
};

int main() {
    clrscr();
    MyString s1("Hello, ");
    MyString s2("World!");

    MyString s3 = s1 + s2; // Using overloaded '+' to concatenate strings

    cout << "s1: ";
    s1.display();
    cout << "s2: ";
    s2.display();
    cout << "Concatenated s3: ";
    s3.display();

    getch();
    return 0;
}
