b) Write a C++ class Seller (S_Name, Product_name, Sales_Quantity, Target_Quantity, Month, Commission). Each salesman deals with a separate product and is assigned a target for a month. At the end of the month his monthly sales is compared with target and commission is calculated as follows:
If Sales_Quantity>Target_Quantity then commission is 25% of extra sales made + 10% of target.
If Sales_Quantity = Target_Quantity then commission is 10% of target. Otherwise commission is zero.
Display salesman information along with commission obtained. (Use array of objects) [Marks 25]

#include <iostream.h>
#include <conio.h>
#include <string.h>

class Seller {
private:
    char S_Name[50];
    char Product_name[50];
    int Sales_Quantity;
    int Target_Quantity;
    char Month[20];
    float Commission;

public:
    // Constructor to initialize the seller
    Seller(const char* name, const char* product, int sales, int target, const char* month) {
        strcpy(S_Name, name);
        strcpy(Product_name, product);
        Sales_Quantity = sales;
        Target_Quantity = target;
        strcpy(Month, month);
        Commission = 0;
    }

    // Function to calculate the commission based on sales
    void calculateCommission() {
        if (Sales_Quantity > Target_Quantity) {
            int extraSales = Sales_Quantity - Target_Quantity;
            Commission = 0.25 * extraSales + 0.10 * Target_Quantity;
        } else if (Sales_Quantity == Target_Quantity) {
            Commission = 0.10 * Target_Quantity;
        } else {
            Commission = 0;
        }
    }

    // Function to display seller information and commission
    void display() {
        cout << "Seller Name: " << S_Name << endl;
        cout << "Product Name: " << Product_name << endl;
        cout << "Month: " << Month << endl;
        cout << "Sales Quantity: " << Sales_Quantity << endl;
        cout << "Target Quantity: " << Target_Quantity << endl;
        cout << "Commission Earned: " << Commission << endl;
        cout << "-----------------------------" << endl;
    }
};

int main() {
    clrscr();

    // Array of Seller objects
    Seller sellers[] = {
        Seller("John Doe", "Smartphones", 120, 100, "April"),
        Seller("Jane Smith", "Laptops", 90, 100, "April"),
        Seller("Alice Johnson", "Tablets", 100, 100, "April")
    };

    const int NUM_SELLERS = sizeof(sellers) / sizeof(sellers[0]);

    // Calculate commissions and display information for all sellers
    for (int i = 0; i < NUM_SELLERS; ++i) {
        sellers[i].calculateCommission();
        sellers[i].display();
    }

    getch();
    return 0;
}
