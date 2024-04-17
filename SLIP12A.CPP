a) Write a C++ program to create a class Date with data members day, month, and year. Use default and parameterized constructor to initialize date and display date in dd-Mon-yyyy format. (Example: Input: 04-01-2021 Output: 04-Jan-2021)
[Marks 15]

#include <iostream.h>
#include <conio.h>

class Date {
private:
    int day, month, year;

public:
    // Default constructor
    Date() : day(1), month(1), year(2000) {}  // Initializing with a default date

    // Parameterized constructor
    Date(int d, int m, int y) : day(d), month(m), year(y) {}

    // Function to display date in dd-Mon-yyyy format
    void display() {
        char *months[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", 
                          "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
        cout << (day < 10 ? "0" : "") << day << "-" << months[month - 1] << "-" << year;
    }
};

int main() {
    clrscr();
    Date defaultDate; // Will use the default constructor
    Date customDate(4, 1, 2021); // Will use the parameterized constructor

    cout << "Default Date: ";
    defaultDate.display();
    cout << "\nCustom Date: ";
    customDate.display();

    getch();
    return 0;
}
