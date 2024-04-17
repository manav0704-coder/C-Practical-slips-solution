a) Write a C++ program to accept Worker information Worker_Name, No_of_Hours_worked, Pay_Rate and Salary. Write necessary functions to calculate and display the salary of Worker. (Use default value for Pay_Rate)
[Marks 15]


#include <iostream.h>
#include <stdio.h>  // For strcpy
#include <conio.h>  // For getch()
#include<string.h>
class Worker {
private:
    char Worker_Name[100];
    int No_of_Hours_worked;
    float Pay_Rate;
    float Salary;

public:
    // Constructor with default value for Pay_Rate
    Worker(const char* name, int hours, float rate = 25.0f) { // Default pay rate is $25.0 per hour
        strcpy(Worker_Name, name);
        No_of_Hours_worked = hours;
        Pay_Rate = rate;
        Salary = 0; // Initialize salary to 0
    }

    // Function to calculate salary
    void calculateSalary() {
        Salary = No_of_Hours_worked * Pay_Rate;
    }

    // Function to display worker information and salary
    void displayInfo() {
        cout << "Worker Name: " << Worker_Name << endl;
        cout << "Hours Worked: " << No_of_Hours_worked << endl;
        cout << "Pay Rate: $" << Pay_Rate << " per hour" << endl;
        cout << "Salary: $" << Salary << endl;
    }
};

void main() {
    clrscr(); // Clear the screen for better readability in Turbo C++
    // Worker with custom pay rate
    Worker worker1("John Doe", 40, 30.0f); // 40 hours, $30.0 per hour
    worker1.calculateSalary();
    worker1.displayInfo();

    cout << endl;

    // Worker with default pay rate
    Worker worker2("Jane Smith", 35); // 35 hours, default pay rate
    worker2.calculateSalary();
    worker2.displayInfo();

    getch(); // Wait for user input before closing program
}
