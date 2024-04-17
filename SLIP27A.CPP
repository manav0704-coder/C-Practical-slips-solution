a) Create a C++ class College, with data members College_Id, College_Name, Establishment_year, University_Name. Overload operators>> and << to accept and display College information.
[Marks 15]    

#include <iostream.h>
#include <conio.h>

class College {
private:
    int College_Id;
    char College_Name[100];
    int Establishment_Year;
    char University_Name[100];

public:
    // Friend function to overload >> operator to input college information
    friend istream& operator>>(istream& in, College& c) {
        cout << "Enter College ID: ";
        in >> c.College_Id;
        in.ignore();  // Ignore newline from the input buffer after reading integer
        cout << "Enter College Name: ";
        in.getline(c.College_Name, 100);
        cout << "Enter Establishment Year: ";
        in >> c.Establishment_Year;
        in.ignore();  // Clear input buffer
        cout << "Enter University Name: ";
        in.getline(c.University_Name, 100);
        return in;
    }

    // Friend function to overload << operator to output college information
    friend ostream& operator<<(ostream& out, College& c) {
        out << "College ID: " << c.College_Id << endl;
        out << "College Name: " << c.College_Name << endl;
        out << "Establishment Year: " << c.Establishment_Year << endl;
        out << "University Name: " << c.University_Name;
        return out;
    }
};

int main() {
    clrscr();
    College college;
    cout << "Enter details for the college:" << endl;
    cin >> college;
    clrscr();
    cout << "You entered the following details:" << endl;
    cout << college;
    getch();
    return 0;
}
