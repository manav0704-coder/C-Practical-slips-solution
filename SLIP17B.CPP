
b) Design two base classes Student (S_id, Name, Class) and Competition (C_id, C_Name). Derive a class Stud_Comp(Rank) from it. Write a menu driven program to perform following functions:
i. Accept information.
ii. Display information.
iii. Display Student Details in the ascending order of Rank of a specified competition.
(Use array of objects)

#include <iostream.h>
#include <conio.h>
#include <string.h>

class Student {
protected:
    int S_id;
    char Name[50];
    char Class[10];
public:
    void acceptStudent() {
        cout << "Enter Student ID: ";
        cin >> S_id;
        cout << "Enter Student Name: ";
        cin >> Name;
        cout << "Enter Class: ";
        cin >> Class;
    }

    void displayStudent() {
        cout << "Student ID: " << S_id << ", Name: " << Name << ", Class: " << Class << endl;
    }
};

class Competition {
protected:
    int C_id;
    char C_Name[50];
public:
    void acceptCompetition() {
        cout << "Enter Competition ID: ";
        cin >> C_id;
        cout << "Enter Competition Name: ";
        cin >> C_Name;
    }

    void displayCompetition() {
        cout << "Competition ID: " << C_id << ", Name: " << C_Name << endl;
    }
};

class Stud_Comp : public Student, public Competition {
private:
    int Rank;
public:
    void accept() {
        acceptStudent();
        acceptCompetition();
        cout << "Enter Rank: ";
        cin >> Rank;
    }

    void display() {
        displayStudent();
        displayCompetition();
        cout << "Rank: " << Rank << endl;
    }

    int getCompetitionId() {
        return C_id;
    }

    int getRank() {
        return Rank;
    }

    static void displayInOrder(Stud_Comp arr[], int n, int compId) {
        Stud_Comp temp;
        // Simple bubble sort based on Rank if Competition ID matches
	for(int i=0; i<n-1; i++) {
            for(int j = 0; j < n - i - 1; j++) {
                if(arr[j].getCompetitionId() == compId && arr[j + 1].getCompetitionId() == compId) {
                    if(arr[j].getRank() > arr[j + 1].getRank()) {
                        temp = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = temp;
                    }
                }
            }
        }
        for(int i = 0; i < n; i++) {
            if(arr[i].getCompetitionId() == compId) {
                arr[i].display();
            }
        }
    }
};

int main() {
    clrscr();
    int n;
    cout << "Enter the number of entries: ";
    cin >> n;

    Stud_Comp *students = new Stud_Comp[n];

    for(int i = 0; i < n; i++) {
        cout << "\nEntry " << i + 1 << endl;
        students[i].accept();
    }

    int choice, compId;
    do {
        cout << "\n1. Display All\n2. Display by Competition Rank\n0. Exit\nEnter choice: ";
        cin >> choice;
        switch(choice) {
            case 1:
                for(int i = 0; i < n; i++) {
                    students[i].display();
                }
                break;
            case 2:
                cout << "Enter Competition ID to sort by rank: ";
                cin >> compId;
                Stud_Comp::displayInOrder(students, n, compId);
                break;
            case 0:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice." << endl;
        }
    } while(choice != 0);

    delete[] students;
    getch();
    return 0;
}
