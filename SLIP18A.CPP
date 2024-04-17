#include <iostream.h>
#include <conio.h>

class Student {
private:
    int Roll_no;
    char S_Name[50];
    char Class[10];
    float Percentage;

public:
    void accept() {
        cout << "Enter Roll Number: ";
        cin >> Roll_no;
        cout << "Enter Student Name: ";
        cin.ignore();  // Ignores the newline left by the previous input
        cin.getline(S_Name, 50);
        cout << "Enter Class: ";
        cin >> Class;
        cout << "Enter Percentage: ";
        cin >> Percentage;
    }

    void display() {
        cout << "Roll Number: " << Roll_no << endl;
        cout << "Student Name: " << S_Name << endl;
        cout << "Class: " << Class << endl;
        cout << "Percentage: " << Percentage << "%" << endl;
    }

    Student compare(Student& other) {
        // Use the this pointer to access the current object's percentage
        if (this->Percentage > other.Percentage) {
            return *this;
        } else {
            return other;
        }
    }
};

int main() {
    clrscr();
    Student student1, student2, highest;

    cout << "Enter details for the first student:\n";
    student1.accept();
    
    cout << "\nEnter details for the second student:\n";
    student2.accept();

    cout << "\nStudent with the highest percentage:\n";
    highest = student1.compare(student2);
    highest.display();

    getch();
    return 0;
}
