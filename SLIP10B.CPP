#include <iostream.h>
#include <conio.h>
#include <stdio.h> // for gets/puts
#include <iomanip.h> // for setw

class City {
    int City_code;
    char City_name[50];
    int population;

public:
    void accept() {
        cout << "Enter city code: ";
        cin >> City_code;
        cout << "Enter city name: ";
        cin.ignore(); // Ignore the newline character left by cin
        gets(City_name); // Using gets for simplicity in Turbo C++
        cout << "Enter population: ";
        cin >> population;
    }

    void display() {
        cout << setw(10) << City_code << setw(20) << City_name << setw(15) << population << endl;
    }

    int getPopulation() const {
        return population;
    }

    friend void sortCities(City [], int);
};

void sortCities(City cities[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (cities[j].getPopulation() > cities[j + 1].getPopulation()) {
                City temp = cities[j];
                cities[j] = cities[j + 1];
                cities[j + 1] = temp;
            }
        }
    }
}

int main() {
    clrscr();
    int n, i;
    cout << "Enter the number of cities: ";
    cin >> n;

    City *cities = new City[n]; // Dynamic allocation

    for (i = 0; i < n; i++) {
        cout << "Enter details for city " << i + 1 << ":" << endl;
        cities[i].accept();
    }

    sortCities(cities, n);

    cout << "\nCities sorted by population:" << endl;
    cout << setw(10) << "City Code" << setw(20) << "City Name" << setw(15) << "Population" << endl;
    for (i = 0; i < n; i++) {
        cities[i].display();
    }

    cout << "\nEnter city code to display details: ";
    int code;
    cin >> code;
    bool found = false;
    for (i = 0; i < n; i++) {
        if (cities[i].City_code == code) {
            cout << "\nDetails of the city: " << endl;
            cout << setw(10) << "City Code" << setw(20) << "City Name" << setw(15) << "Population" << endl;
            cities[i].display();
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "City not found." << endl;
    }

    delete[] cities; // Free the allocated memory
    getch();
    return 0;
}
