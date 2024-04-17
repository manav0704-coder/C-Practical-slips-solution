#include <iostream.h>
#include <conio.h>
#include <string.h>

// Virtual base class
class Student {
protected:
    int rollNo;
    char name[50];

public:
    void acceptStudentInfo() {
        cout << "Enter Roll Number: ";
        cin >> rollNo;
        cout << "Enter Name: ";
        cin.ignore(); // To consume the newline character left by cin
        cin.getline(name, 50);
    }

    void displayStudentInfo() {
        cout << "Roll Number: " << rollNo << endl;
        cout << "Name: " << name << endl;
    }
};

class Theory : virtual public Student {
protected:
    int M1, M2, M3, M4;

public:
    void acceptMarks() {
        cout << "Enter marks for M1, M2, M3, M4: ";
        cin >> M1 >> M2 >> M3 >> M4;
    }
};

class Practical : virtual public Student {
protected:
    int P1, P2;

public:
    void acceptPracticalMarks() {
        cout << "Enter marks for P1 and P2: ";
        cin >> P1 >> P2;
    }
};

class Result : public Theory, public Practical {
private:
    int totalMarks;
    float percentage;
    char grade;

public:
    void calculate() {
        totalMarks = M1 + M2 + M3 + M4 + P1 + P2;
        percentage = totalMarks / 6.0f;
        if (percentage >= 90) grade = 'A';
        else if (percentage >= 75) grade = 'B';
        else if (percentage >= 50) grade = 'C';
        else grade = 'D';
    }

    void displayResult() {
        displayStudentInfo();
        cout << "Total Marks: " << totalMarks << endl;
        cout << "Percentage: " << percentage << "%" << endl;
        cout << "Grade: " << grade << endl;
    }
};

int main() {
    clrscr();
    Result student;
    int choice;
    do {
        cout << "\n1. Accept Student Information\n";
        cout << "2. Display Student Information\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                student.acceptStudentInfo();
                student.acceptMarks();
                student.acceptPracticalMarks();
                student.calculate();
                break;
            case 2:
                student.displayResult();
                break;
            case 3:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice, please try again.\n";
        }
    } while (choice != 3);
    getch();
    return 0;
}
