
b) Create a C++ class Employee with data members Emp_Id, Emp_Name, Mobile_No, Salary. Write necessary member functions for the following:
i. Accept details of n employees
ii. Display employee details in descending order of their salary.
iii. Display details of a particular employee.
(Use Array of object and Use appropriate manipulators)
[Marks 25]      

#include <iostream.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

class Employee {
    char Emp_Id[10];
    char Emp_Name[50];
    char Mobile_No[15];
    float Salary;

public:
    void acceptDetails(); // Accept details of an employee
    void displayDetails(); // Display details of an employee
    friend void displayInDescendingOrder(Employee emp[], int n);
    friend void displayParticularEmployee(Employee emp[], int n, const char* id);
};

void Employee::acceptDetails() {
    cout << "Enter Employee ID: ";
    cin >> Emp_Id;
    cout << "Enter Name: ";
    cin >> Emp_Name;
    cout << "Enter Mobile Number: ";
    cin >> Mobile_No;
    cout << "Enter Salary: ";
    cin >> Salary;
}

void Employee::displayDetails() {
    cout << "Employee ID: " << Emp_Id << ", Name: " << Emp_Name
         << ", Mobile No: " << Mobile_No << ", Salary: " << Salary << endl;
}

void displayInDescendingOrder(Employee emp[], int n) {
    // Simple Bubble Sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (emp[j].Salary < emp[j + 1].Salary) {
                Employee temp = emp[j];
                emp[j] = emp[j + 1];
                emp[j + 1] = temp;
            }
        }
    }
    cout << "\nEmployees in descending order of salary:\n";
    for (int i = 0; i < n; i++) {
        emp[i].displayDetails();
    }
}

void displayParticularEmployee(Employee emp[], int n, const char* id) {
    for (int i = 0; i < n; i++) {
        if (strcmp(emp[i].Emp_Id, id) == 0) {
            cout << "\nDetails of Employee ID " << id << ":\n";
            emp[i].displayDetails();
            return;
        }
    }
    cout << "Employee with ID " << id << " not found.\n";
}

int main() {
    clrscr();
    int n;
    cout << "Enter the number of employees: ";
    cin >> n;

    Employee* emp = new Employee[n];

    for (int i = 0; i < n; i++) {
        cout << "\nEnter details for employee " << i + 1 << ":\n";
        emp[i].acceptDetails();
    }

    displayInDescendingOrder(emp, n);

    char searchId[10];
    cout << "\nEnter Employee ID to search: ";
    cin >> searchId;
    displayParticularEmployee(emp, n, searchId);

    delete[] emp;
    getch();
    return 0;
}
