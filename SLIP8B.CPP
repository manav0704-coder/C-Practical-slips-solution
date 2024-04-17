#include <iostream.h>
#include <conio.h>
#include <string.h>

class Person {
private:
    char Person_name[100];
    char Mobile_number[15];
    int Age;
    char City[100];

public:
    Person(const char* name, const char* mobile, int age, const char* city) {
        strcpy(Person_name, name);
        strcpy(Mobile_number, mobile);
        Age = age;
        strcpy(City, city);
    }

    // Search the mobile number of a given person (by name)
    void search(const char* name) {
        if (strcmp(Person_name, name) == 0) {
            cout << "Mobile Number: " << Mobile_number << endl;
        }
    }

    // Search the person name by mobile number
    void searchByMobile(const char* mobile) {
        if (strcmp(Mobile_number, mobile) == 0) {
            cout << "Person Name: " << Person_name << endl;
        }
    }

    // Search all persons from a given city
    void searchByCity(const char* city) {
        if (strcmp(City, city) == 0) {
            cout << "Name: " << Person_name << ", Mobile: " << Mobile_number << ", Age: " << Age << endl;
	}
    }

    // Utility to display person details
    void display() {
	cout << "Name: " << Person_name << ", Mobile: " << Mobile_number << ", Age: " << Age << ", City: " << City << endl;
    }
};

void main() {
    clrscr();
    int i;
    Person people[] = {
	Person("John Doe", "1234567890", 30, "New York"),
	Person("Jane Smith", "0987654321", 28, "Los Angeles"),
	Person("Alice Johnson", "555667788", 35, "New York")
    };
    int n = sizeof(people) / sizeof(Person);

    cout << "Search by Name ('John Doe'):\n";
    for ( i = 0; i < n; i++) {
	people[i].search("John Doe");
    }

    cout << "\nSearch by Mobile ('0987654321'):\n";
    for ( i = 0; i < n; i++) {
	people[i].searchByMobile("0987654321");
    }

    cout << "\nSearch by City ('New York'):\n";
    for ( i = 0; i < n; i++) {
        people[i].searchByCity("New York");
    }

    getch();
}
