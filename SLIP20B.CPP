b) Create a C++ class for inventory of Mobiles with data members Model, Mobile _Company, Color, Price and Quantity. Mobile can be sold, if stock is available, otherwise purchase will be made. Write necessary member functions for the following:
i. To accept mobile details from user.
ii. To sale a mobile. (Sale contains Mobile details & number of mobiles to be sold.)
iii. To Purchase a Mobile. (Purchase contains Mobile details & number of mobiles to be purchased)
[Marks 25]

#include <iostream.h>
#include <conio.h>
#include <string.h>

class Mobile {
private:
    char Model[50];
    char Mobile_Company[50];
    char Color[20];
    float Price;
    int Quantity;

public:
    Mobile() {  // Default constructor
        strcpy(Model, "");
        strcpy(Mobile_Company, "");
        strcpy(Color, "");
        Price = 0.0;
        Quantity = 0;
    }

    void acceptDetails() {
        cout << "\nEnter Model: ";
        cin >> Model;
        cout << "Enter Mobile Company: ";
        cin >> Mobile_Company;
        cout << "Enter Color: ";
        cin >> Color;
        cout << "Enter Price: ";
        cin >> Price;
        cout << "Enter Quantity: ";
        cin >> Quantity;
    }

    void displayDetails() {
        cout << "\nModel: " << Model;
        cout << "\nMobile Company: " << Mobile_Company;
        cout << "\nColor: " << Color;
        cout << "\nPrice: " << Price;
        cout << "\nQuantity: " << Quantity << "\n";
    }

    void sellMobile(int num) {
        if (Quantity >= num) {
            Quantity -= num;
            cout << "\nSold " << num << " units of " << Model << "\n";
        } else {
            cout << "\nInsufficient stock. Only " << Quantity << " units available.\n";
        }
    }

    void purchaseMobile(int num) {
        Quantity += num;
        cout << "\nPurchased " << num << " more units of " << Model << "\n";
    }
};

int main() {
    Mobile inventory;
    int choice, num;

    clrscr();

    do {
        cout << "\n1. Accept Mobile Details";
        cout << "\n2. Display Mobile Details";
        cout << "\n3. Sell Mobile";
        cout << "\n4. Purchase Mobile";
        cout << "\n5. Exit";
        cout << "\n\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                inventory.acceptDetails();
                break;
            case 2:
                inventory.displayDetails();
                break;
            case 3:
                cout << "Enter number of mobiles to sell: ";
                cin >> num;
                inventory.sellMobile(num);
                break;
            case 4:
                cout << "Enter number of mobiles to purchase: ";
                cin >> num;
                inventory.purchaseMobile(num);
                break;
            case 5:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid option. Please try again.\n";
                break;
        }
    } while (choice != 5);

    getch();
    return 0;
}
