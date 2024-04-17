
a) Write a C++ program to create a class E_Bill with data members Cust_Name, Meter_ID, No_of_Units and Total_Charges. Write member functions to accept and display customer information by calculating charges. (Rules to calculate electricity board charges)
For first 100 units Rs. 1 per unit
For next 200 units Rs. 2 per unit
Beyond 300 units Rs. 5 per unit
All users are charged a minimum of Rs.150. If the total charge is more than Rs.250.00 then an additional charge of 15% is added.
[Marks 15]


#include <iostream.h>
#include <conio.h>

class E_Bill {
    char Cust_Name[100];
    char Meter_ID[50];
    int No_of_Units;
    float Total_Charges;

public:
    void acceptDetails(); // To input customer details
    void calculateCharges(); // To calculate electricity charges
    void displayBill(); // To display the bill
};

void E_Bill::acceptDetails() {
    cout << "Enter Customer Name: ";
    cin.getline(Cust_Name, 100);
    cout << "Enter Meter ID: ";
    cin >> Meter_ID;
    cout << "Enter Number of Units consumed: ";
    cin >> No_of_Units;
}

void E_Bill::calculateCharges() {
    Total_Charges = 0;
    if (No_of_Units <= 100) {
        Total_Charges = No_of_Units * 1;
    } else if (No_of_Units <= 300) {
        Total_Charges = 100 + (No_of_Units - 100) * 2;
    } else {
        Total_Charges = 100 + 200 * 2 + (No_of_Units - 300) * 5;
    }

    Total_Charges = max(150, Total_Charges); // Ensuring minimum charge

    if (Total_Charges > 250) {
        Total_Charges += Total_Charges * 0.15; // Adding 15% additional charges
    }
}

void E_Bill::displayBill() {
    cout << "\nCustomer Name: " << Cust_Name
         << "\nMeter ID: " << Meter_ID
         << "\nUnits Consumed: " << No_of_Units
         << "\nTotal Charges: Rs. " << Total_Charges << endl;
}

int main() {
    clrscr();
    E_Bill bill;

    bill.acceptDetails();
    bill.calculateCharges();
    bill.displayBill();

    getch();
    return 0;
}
