#include <iostream.h>
#include <conio.h>
#include <iomanip.h>
#include <string.h>

class Marksheet {
private:
    char Seat_No[10];
    char Student_Name[50];
    char Class[20];
    char Subject_Name[5][30];
    int Int_Marks[5];
    int Ext_Marks[5];
    int Total[5];
    int Grand_Total;
    float Percentage;
    char Grade;

    void calculateTotal() {
        Grand_Total = 0;
        for (int i = 0; i < 5; i++) {
            Total[i] = Int_Marks[i] + Ext_Marks[i];
            Grand_Total += Total[i];
        }
    }

    void calculatePercentage() {
        Percentage = (float)Grand_Total / 5;
    }

    void calculateGrade() {
        if (Percentage >= 90) Grade = 'A';
        else if (Percentage >= 75) Grade = 'B';
        else if (Percentage >= 60) Grade = 'C';
        else if (Percentage >= 50) Grade = 'D';
        else Grade = 'F';
    }

public:
    void accept();
    void display();
};

void Marksheet::accept() {
    cout << "Enter Seat Number: ";
    cin >> Seat_No;
    cout << "Enter Student Name: ";
    cin.ignore();
    cin.getline(Student_Name, 50);
    cout << "Enter Class: ";
    cin.getline(Class, 20);

    for (int i = 0; i < 5; i++) {
        cout << "Enter Subject " << (i + 1) << " Name: ";
        cin.getline(Subject_Name[i], 30);
        cout << "Enter Internal Marks (out of 100): ";
        cin >> Int_Marks[i];
        cout << "Enter External Marks (out of 100): ";
        cin >> Ext_Marks[i];
    }

    calculateTotal();
    calculatePercentage();
    calculateGrade();
}

void Marksheet::display() {
    cout << setfill('=') << setw(70) << "=" << endl;
    cout << setfill(' ') << "Seat No: " << Seat_No << endl;
    cout << "Name: " << Student_Name << endl;
    cout << "Class: " << Class << endl;

    cout << setw(15) << "Subject" << setw(15) << "Internal" << setw(15) << "External" << setw(15) << "Total" << endl;

    for (int i = 0; i < 5; i++) {
        cout << setw(15) << Subject_Name[i] << setw(15) << Int_Marks[i] << setw(15) << Ext_Marks[i] << setw(15) << Total[i] << endl;
    }

    cout << "Grand Total: " << Grand_Total << endl;
    cout << "Percentage: " << setprecision(2) << fixed << Percentage << "%" << endl;
    cout << "Grade: " << Grade << endl;
    cout << setfill('=') << setw(70) << "=" << endl;
}

int main() {
    clrscr();

    Marksheet student;
    student.accept();
    student.display();

    getch();
    return 0;
}
