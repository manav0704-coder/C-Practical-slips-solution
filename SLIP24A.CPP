#include <iostream.h>
#include <conio.h>
#include <string.h>

class FixDeposit {
private:
    int FD_No;
    char Cust_Name[50];
    float FD_Amt;
    float Interest_rate;
    float Maturity_amt;
    int Number_of_months;

public:
    // Parameterized constructor with a default value for the interest rate
    FixDeposit(int fdno, const char* name, float fdamt, int months, float intrate = 0.05) {
        FD_No = fdno;
        strcpy(Cust_Name, name);
        FD_Amt = fdamt;
        Number_of_months = months;
        Interest_rate = intrate;
        calculateMaturity();
    }

    // Function to calculate maturity amount
    void calculateMaturity() {
        Maturity_amt = FD_Amt * (1 + Interest_rate * (Number_of_months / 12.0));
    }

    // Function to display details
    void displayDetails() {
        cout << "FD Number: " << FD_No << "\n";
        cout << "Customer Name: " << Cust_Name << "\n";
        cout << "Fixed Deposit Amount: " << FD_Amt << "\n";
        cout << "Interest Rate: " << (Interest_rate * 100) << "%\n";
        cout << "Number of Months: " << Number_of_months << "\n";
        cout << "Maturity Amount: " << Maturity_amt << "\n";
    }
};

int main() {
    clrscr();
    FixDeposit fd1(101, "John Doe", 10000, 24, 0.07);
    FixDeposit fd2(102, "Jane Smith", 5000, 36); // Using default interest rate

    cout << "Details of FD1:\n";
    fd1.displayDetails();
    cout << "\nDetails of FD2:\n";
    fd2.displayDetails();

    getch();
    return 0;
}
