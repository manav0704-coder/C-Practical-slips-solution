
b) Create a C++ class InvoiceBill with data members Order id, O Date, Customer Name, No of Products, Prod Name[], Quantity[], Prod Price[]. A Customer can buy 'n' products. Accept quantity for each product. Generate and Display the bill using appropriate Manipulators. (Use new operator)
marks[25]

#include <iostream.h>
#include <conio.h>
#include <iomanip.h>
#include <stdio.h>
#include<string.h>

class InvoiceBill {
private:
    int OrderId;
    char ODate[11]; // Assuming date is in YYYY-MM-DD format
    char CustomerName[50];
    int NoOfProducts;
    char **ProdName;
    int *Quantity;
    float *ProdPrice;

public:
      int i;
    InvoiceBill(int orderId, const char* oDate, const char* customerName, int noOfProducts) {
	OrderId = orderId;
	strcpy(ODate, oDate);
	strcpy(CustomerName, customerName);
	NoOfProducts = noOfProducts;

	// Allocate memory for products details
	ProdName = new char*[NoOfProducts];
	Quantity = new int[NoOfProducts];
	ProdPrice = new float[NoOfProducts];


	for ( i = 0; i < NoOfProducts; i++) {
	    ProdName[i] = new char[50];
	}
    }

    ~InvoiceBill() {
	// Free dynamically allocated memory
	for (int i = 0; i < NoOfProducts; i++) {
            delete[] ProdName[i];
        }
        delete[] ProdName;
        delete[] Quantity;
        delete[] ProdPrice;
    }

    void acceptDetails() {
        cout << "Enter product details for order ID " << OrderId << ":\n";
	for (int i = 0; i < NoOfProducts; i++) {
            cout << "Product " << (i + 1) << " name: ";
            cin.getline(ProdName[i], 50);
            cout << "Quantity: ";
            cin >> Quantity[i];
            cout << "Price: ";
            cin >> ProdPrice[i];
            cin.ignore(); // Clear buffer after reading numeric input
        }
    }

    void displayBill() {
        cout << "\nInvoice for Order ID: " << OrderId << "\n";
        cout << "Date: " << ODate << "\n";
        cout << "Customer Name: " << CustomerName << "\n";
        cout << setprecision(2) << setiosflags(ios::fixed);
        float total = 0;
	for (int i = 0; i < NoOfProducts; i++) {
            float subtotal = Quantity[i] * ProdPrice[i];
            total += subtotal;
	    cout << setw(30)  << ProdName[i]
		 << setw(10)  << Quantity[i]
		 << setw(10)  << ProdPrice[i]
		 << setw(10)  << subtotal << "\n";
        }
	cout << setw(50) << "Total Amount: " << total << "\n";
    }
};

int main() {
    clrscr();
    InvoiceBill bill(1234, "2024-04-15", "John Doe", 2);
    bill.acceptDetails();
    bill.displayBill();
    getch();
    return 0;
}
