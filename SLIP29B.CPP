b) Create a
C++ class VisitingStaff with data members Name, No_of_Subjects, Name_of_Subjects[], Working_hours, Total_Salary. (Number of subjects varies for a Staff). Write a parameterized constructor to initialize the data members and create an array for Name_of_Subjects dynamically. Display Visiting Staff details by calculating salary. (Assume remuneration Rs. 300 per working hour) [Marks 25] 

#include <iostream.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

class VisitingStaff {
    char Name[50];
    int No_of_Subjects;
    char **Name_of_Subjects; // Pointer to pointer for dynamic array of strings
    int Working_hours;
    float Total_Salary;

public:
    // Parameterized constructor
    VisitingStaff(char *name, int no_of_subjects, char subjects[][50], int working_hours);
    ~VisitingStaff(); // Destructor to deallocate dynamic memory
    void calculateSalary(); // Calculates the total salary based on working hours
    void displayDetails(); // Display staff details
};

// Constructor implementation
VisitingStaff::VisitingStaff(char *name, int no_of_subjects, char subjects[][50], int working_hours) {
    strcpy(Name, name);
    No_of_Subjects = no_of_subjects;
    Working_hours = working_hours;
    Total_Salary = 0;

    // Allocate memory for subjects array
    Name_of_Subjects = new char*[No_of_Subjects];
    for (int i = 0; i < No_of_Subjects; i++) {
        Name_of_Subjects[i] = new char[50];
        strcpy(Name_of_Subjects[i], subjects[i]);
    }
}

// Destructor to free allocated memory
VisitingStaff::~VisitingStaff() {
    for (int i = 0; i < No_of_Subjects; i++) {
        delete[] Name_of_Subjects[i];
    }
    delete[] Name_of_Subjects;
}

void VisitingStaff::calculateSalary() {
    Total_Salary = Working_hours * 300; // Rs. 300 per working hour
}

void VisitingStaff::displayDetails() {
    cout << "\nName: " << Name
         << "\nNumber of Subjects: " << No_of_Subjects
         << "\nSubjects: ";
    for (int i = 0; i < No_of_Subjects; i++) {
        cout << Name_of_Subjects[i] << ", ";
    }
    cout << "\nWorking Hours: " << Working_hours
         << "\nTotal Salary: Rs. " << Total_Salary << endl;
}

int main() {
    clrscr();
    char subjects[][50] = {"Mathematics", "Physics"};
    VisitingStaff staff("John Doe", 2, subjects, 120);

    staff.calculateSalary();
    staff.displayDetails();

    getch();
    return 0;
}
