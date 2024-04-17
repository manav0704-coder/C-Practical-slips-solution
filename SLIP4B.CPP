b) Write a C++ program to create a base class Employee (Emp-code, name, salary). Derive two classes as Fulltime (daily_wages, number_of_days) and Parttime (number_of_working_hours, hourly_wages).
Write a menu driven program to perform following functions:
1. Accept the details of 'n' employees and calculate the salary.
2. Display the details of 'n' employees.
3. Display the details of employee having maximum salary for both types of employees.
[Marks 25]

#include <iostream.h>
#include <conio.h>

class Employee {
protected:
    int Emp_code;
    char name[100];
    float salary;

public:
    virtual void accept() = 0;
    virtual void calculateSalary() = 0;
    virtual void display() = 0;
    float getSalary() const {
        return salary;
    }
};

class Fulltime : public Employee {
    float daily_wages;
    int number_of_days;

public:
    void accept() {
        cout << "Enter Employee Code: ";
        cin >> Emp_code;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Daily Wages: ";
        cin >> daily_wages;
        cout << "Enter Number of Days Worked: ";
        cin >> number_of_days;
    }

    void calculateSalary() {
        salary = daily_wages * number_of_days;
    }

    void display() {
        cout << "Employee Code: " << Emp_code << ", Name: " << name
             << ", Salary: $" << salary << " [Fulltime]\n";
    }
};

class Parttime : public Employee {
    int number_of_working_hours;
    float hourly_wages;

public:
    void accept() {
        cout << "Enter Employee Code: ";
        cin >> Emp_code;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Hourly Wages: ";
        cin >> hourly_wages;
        cout << "Enter Number of Working Hours: ";
        cin >> number_of_working_hours;
    }

    void calculateSalary() {
        salary = hourly_wages * number_of_working_hours;
    }

    void display() {
        cout << "Employee Code: " << Emp_code << ", Name: " << name
             << ", Salary: $" << salary << " [Parttime]\n";
    }
};

void displayMax(Employee **emp, int n, const char *type) {
    float maxSalary = 0;
    int index = -1;
    for (int i = 0; i < n; i++) {
        if (emp[i]->getSalary() > maxSalary) {
            maxSalary = emp[i]->getSalary();
            index = i;
        }
    }
    if (index != -1) {
        cout << "Highest Salary of " << type << " Employee:\n";
        emp[index]->display();
    } else {
        cout << "No " << type << " employees found.\n";
    }
}

void main() {
    clrscr();
    int n, choice,i;
    cout << "Enter number of employees: ";
    cin >> n;
    Employee **emp = new Employee*[n];
    int ftCount = 0, ptCount = 0;

    do {
	cout << "\n1. Accept Fulltime Employees\n";
	cout << "2. Accept Parttime Employees\n";
	cout << "3. Display All Employees\n";
	cout << "4. Display Employee with Maximum Salary (Fulltime)\n";
	cout << "5. Display Employee with Maximum Salary (Parttime)\n";
	cout << "6. Exit\n";
	cout << "Enter your choice: ";
	cin >> choice;

	switch (choice) {
	    case 1:
		for ( i = ftCount; i < n && ftCount + ptCount < n; i++) {
		    emp[i] = new Fulltime;
		    emp[i]->accept();
		    emp[i]->calculateSalary();
		    ftCount++;
		}
		break;
	    case 2:
		for ( i = ftCount + ptCount; i < n && ftCount + ptCount < n; i++) {
		    emp[i] = new Parttime;
		    emp[i]->accept();
		    emp[i]->calculateSalary();
		    ptCount++;
		}
		break;
	    case 3:
		for ( i = 0; i < ftCount + ptCount; i++) {
		    emp[i]->display();
		}
		break;
	    case 4:
		displayMax(emp, ftCount, "Fulltime");
		break;
	    case 5:
		displayMax(emp + ftCount, ptCount, "Parttime");
		break;
	    case 6:
		break;
	    default:
		cout << "Invalid choice! Please choose again.\n";
		break;
	}
    } while (choice != 6);

    getch();
}
