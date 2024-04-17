a) Consider the following C++ class
class Person
{
char Name [20];
charAddr [30];
float Salary;
float tax amount;
public:
// member functions
};
Calculate tax amount by checking salary of a person
For salary <=20000
For salary >20000||<=40000
For salary >40000
tax rate=0
tax rate 5% of salary.
tax rate 10% of salary.
[Marks 15]


#include <iostream.h>
#include <conio.h>
#include <string.h> // For strcpy

class Person {
    char Name[20];
    char Addr[30];
    float Salary;
    float TaxAmount;

public:
    // Constructor to initialize the data members
    void init(char name[], char addr[], float salary) {
        strcpy(Name, name);
        strcpy(Addr, addr);
        Salary = salary;
        TaxAmount = 0.0;  // Initialize tax amount to zero
        calculateTax();   // Calculate tax based on the salary
    }

    void calculateTax() {
        if (Salary <= 20000) {
            TaxAmount = 0;
        } else if (Salary > 20000 && Salary <= 40000) {
            TaxAmount = Salary * 0.05;  // 5% tax
        } else if (Salary > 40000) {
            TaxAmount = Salary * 0.10;  // 10% tax
        }
    }

    void display() {
        cout << "Name: " << Name << ", Address: " << Addr << ", Salary: " << Salary << ", Tax Amount: " << TaxAmount << endl;
    }
};

void main() {
    clrscr();
    Person person1, person2, person3;

    person1.init("John Doe", "123 Elm St", 19000);
    person2.init("Jane Smith", "456 Oak St", 25000);
    person3.init("Robert Brown", "789 Pine St", 45000);

    person1.display();
    person2.display();
    person3.display();

    getch();
}
