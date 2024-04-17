a) Write a C++ program to create a class Machine with data members Machine_Id, Machine_Name, Price. Create and initialize all values of Machine object by using parameterized constructor and copy constructor. Display details of Machine using setw() and setprecision().
[Marks 15]

#include <iostream.h>
#include <iomanip.h>   // Required for setw() and setprecision()
#include <conio.h>     // Required for getch()
#include <string.h>    // Required for strcpy()

class Machine {
private:
    int Machine_Id;
    char Machine_Name[50];
    float Price;

public:
    // Parameterized constructor
    Machine(int id, const char* name, float price) {
        Machine_Id = id;
        strcpy(Machine_Name, name);
        Price = price;
    }

    // Copy constructor
    Machine(const Machine& m) {
        Machine_Id = m.Machine_Id;
        strcpy(Machine_Name, m.Machine_Name);
        Price = m.Price;
    }

    // Function to display machine details
    void display() {
        cout << setw(10) << "ID: " << Machine_Id << endl;
        cout << setw(15) << "Machine Name: " << Machine_Name << endl;
	cout << setw(10) << "Price: $" << setprecision(2) << Price << endl;
        cout << "--------------------------------" << endl;
    }
};

int main() {
    clrscr();

    // Create a Machine object using a parameterized constructor
    Machine machine1(101, "Lathe", 4500.75);

    // Create a Machine object using the copy constructor
    Machine machine2 = machine1;

    // Display details of both machines
    cout << "Machine 1 Details:" << endl;
    machine1.display();
    cout << "Machine 2 Details (Copy of Machine 1):" << endl;
    machine2.display();

    getch();
    return 0;
}
