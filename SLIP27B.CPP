#include <iostream.h>
#include <conio.h>
#include <string.h>

class Travels {
protected:
    int T_no;
    char Company_Name[50];

public:
    void acceptTravels() {
        cout << "Enter Travel Number: ";
        cin >> T_no;
        cin.ignore(); // Clearing buffer
        cout << "Enter Company Name: ";
        cin.getline(Company_Name, 50);
    }

    void displayTravels() {
        cout << "Travel Number: " << T_no << endl;
        cout << "Company Name: " << Company_Name << endl;
    }
};

class Route : public Travels {
protected:
    int Route_id;
    char Source[50];
    char Destination[50];

public:
    void acceptRoute() {
        acceptTravels();
        cout << "Enter Route ID: ";
        cin >> Route_id;
        cin.ignore(); // Clearing buffer
        cout << "Enter Source: ";
        cin.getline(Source, 50);
        cout << "Enter Destination: ";
        cin.getline(Destination, 50);
    }

    void displayRoute() {
        displayTravels();
        cout << "Route ID: " << Route_id << endl;
        cout << "Source: " << Source << endl;
        cout << "Destination: " << Destination << endl;
    }
};

class Reservation : public Route {
private:
    int Number_of_Seats;
    char Travels_Class[20];
    float Fare;
    char Travel_Date[15];

public:
    void acceptReservation() {
        acceptRoute();
        cout << "Enter Number of Seats: ";
        cin >> Number_of_Seats;
        cin.ignore(); // Clearing buffer
        cout << "Enter Class of Travel: ";
        cin.getline(Travels_Class, 20);
        cout << "Enter Fare: ";
        cin >> Fare;
        cin.ignore(); // Clearing buffer
        cout << "Enter Travel Date (dd/mm/yyyy): ";
        cin.getline(Travel_Date, 15);
    }

    void displayReservation() {
        displayRoute();
        cout << "Number of Seats: " << Number_of_Seats << endl;
        cout << "Class of Travel: " << Travels_Class << endl;
        cout << "Fare: " << Fare << endl;
        cout << "Travel Date: " << Travel_Date << endl;
    }

    char* getDate() {
        return Travel_Date;
    }
};

void displayByDate(Reservation res[], int n, char date[]) {
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(res[i].getDate(), date) == 0) {
            res[i].displayReservation();
            found = 1;
        }
    }
    if (!found) {
        cout << "No reservations found on " << date << endl;
    }
}

int main() {
    clrscr();
    int n;
    cout << "Enter number of reservations: ";
    cin >> n;
    cin.ignore(); // Clear buffer

    Reservation *reservations = new Reservation[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter details for reservation " << i + 1 << ":" << endl;
        reservations[i].acceptReservation();
    }

    clrscr();

    cout << "Displaying all reservations:" << endl;
    for (int i = 0; i < n; i++) {
        reservations[i].displayReservation();
    }

    char date[15];
    cout << "Enter date to display reservations (dd/mm/yyyy): ";
    cin.getline(date, 15);
    displayByDate(reservations, n, date);

    delete[] reservations;
    getch();
    return 0;
}
