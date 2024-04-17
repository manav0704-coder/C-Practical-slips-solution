a) Create a C++ class Employee with data members Emp_id, Emp_Name, Company_Name and Salary. Write member functions to accept and display Employee information. Design User defined Manipulator to print Salary.
(For Salary set right justification, maximum width to 7 and fill remaining spaces with '*')

#include <iostream.h>
#include <conio.h>
#include <iomanip.h>
#include <string.h>

class Employee {
private:
    int Emp_id;
    char Emp_Name[100];
    char Company_Name[100];
    float Salary;

public:
    void accept() {
        cout << "Enter Employee ID: ";
        cin >> Emp_id;
        cout << "Enter Employee Name: ";
        cin.ignore();  // Ignore any newline in the buffer.
        cin.getline(Emp_Name, 100);
        cout << "Enter Company Name: ";
        cin.getline(Company_Name, 100);
        cout << "Enter Salary: ";
        cin >> Salary;
    }

    void display() {
        cout << "Employee ID: " << Emp_id << "\n";
        cout << "Employee Name: " << Emp_Name << "\n";
        cout << "Company Name: " << Company_Name << "\n";
        cout << "Salary: ";
        printSalary(Salary);
        cout << "\n";
    }

    // User-defined manipulator function
    void printSalary(float salary) {
        cout.width(7);      // Set the width to 7
        cout.fill('*');     // Fill the remaining space with '*'
        cout.setf(ios::right);  // Set the output to right-justified
        cout << salary;
    }
};

int main() {
    Employee emp;

    clrscr();
    emp.accept();
    emp.display();

    getch();
    return 0;
}
