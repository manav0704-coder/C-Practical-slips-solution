a) Write a C++ program to create a class Account with data members Acc_number, Acc_type and Balance. Write member functions to accept and display 'n' account details. (Use dynamic memory allocation)
[Marks 15]

#include <iostream.h>
#include <conio.h>
#include <stdio.h> // for gets/puts

class Account {
    int Acc_number;
    char Acc_type[10];
    double Balance;

public:
    void accept() {
        cout << "Enter account number: ";
        cin >> Acc_number;
        cout << "Enter account type: ";
        cin.ignore(); // To ignore the newline character left by cin
        gets(Acc_type); // Using gets for Turbo C++ compatibility
        cout << "Enter balance: ";
        cin >> Balance;
    }

    void display() {
        cout << "Account Number: " << Acc_number << endl;
        cout << "Account Type: " << Acc_type << endl;
        cout << "Balance: $" << Balance << endl;
    }
};

int main() {
    clrscr();
    int n, i;

    cout << "Enter the number of accounts: ";
    cin >> n;

    Account *accounts = new Account[n]; // Dynamic allocation of an array of Account objects

    for (i = 0; i < n; i++) {
        cout << "Enter details for account " << i + 1 << ":" << endl;
        accounts[i].accept();
    }

    cout << "\nDisplaying Account Details:" << endl;
    for (i = 0; i < n; i++) {
        cout << "\nAccount " << i + 1 << ":" << endl;
        accounts[i].display();
    }

    delete[] accounts; // Freeing the allocated memory
    getch();
    return 0;
}
