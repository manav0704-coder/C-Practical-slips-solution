#include <iostream.h>
#include <conio.h>
#include <stdio.h>  // For gets() and puts()

class Product {
private:
    int Product_id;
    char Product_Name[50];
    int Qty;
    double Price;
    static int count;  // Static member to keep track of objects

public:
    // Constructor to initialize and increment object count
    Product() {
        Product_id = 0;
        Product_Name[0] = '\0';
        Qty = 0;
        Price = 0.0;
        count++;
    }

    // Static function to display count of objects
    static void displayCount() {
        cout << "Number of product objects created: " << count << endl;
    }

    // Function to accept product details
    void accept() {
        cout << "Enter product ID: ";
        cin >> Product_id;
        cin.ignore();  // Clear input buffer before taking string input
        cout << "Enter product name: ";
        gets(Product_Name);
        cout << "Enter quantity: ";
        cin >> Qty;
        cout << "Enter price: ";
        cin >> Price;
    }

    // Function to display product details
    void display() const {
        cout << "Product ID: " << Product_id << endl;
        cout << "Product Name: ";
        puts(Product_Name);
        cout << "Quantity: " << Qty << endl;
        cout << "Price: " << Price << endl;
    }
};

int Product::count = 0;  // Initialize static member

int main() {
    clrscr();
    Product p1, p2;

    cout << "Enter details for Product 1:" << endl;
    p1.accept();
    cout << "Enter details for Product 2:" << endl;
    p2.accept();

    clrscr();
    cout << "Product 1 details:" << endl;
    p1.display();
    cout << "Product 2 details:" << endl;
    p2.display();

    Product::displayCount();

    getch();
    return 0;
}
