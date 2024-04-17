b) Create a C++ base class Media. Derive two different classes from it, class NewsPaper with data members N_Name, N_Editor, N_Price, No_of_Pages and class Magazine with data members M_Name, M_Editor, M_Price. Write a C++ program to accept and display information of both NewsPaper and Magazine. (Use pure virtual function) 
[Marks 25]


#include <iostream.h>
#include <conio.h>

// Base class Media with pure virtual functions
class Media {
public:
    virtual void accept() = 0;  // Pure virtual function to accept data
    virtual void display() const = 0;  // Pure virtual function to display data
};

// Derived class NewsPaper
class NewsPaper : public Media {
private:
    char N_Name[100];
    char N_Editor[100];
    float N_Price;
    int No_of_Pages;

public:
    void accept() {
        cout << "Enter Newspaper name: ";
        cin.getline(N_Name, 100);
        cout << "Enter Editor's name: ";
        cin.getline(N_Editor, 100);
        cout << "Enter Price: ";
        cin >> N_Price;
        cout << "Enter Number of Pages: ";
        cin >> No_of_Pages;
        cin.ignore();  // Ignore newline char in the buffer
    }

    void display() const {
        cout << "Newspaper Name: " << N_Name << endl;
        cout << "Editor: " << N_Editor << endl;
        cout << "Price: " << N_Price << endl;
        cout << "Number of Pages: " << No_of_Pages << endl;
    }
};

// Derived class Magazine
class Magazine : public Media {
private:
    char M_Name[100];
    char M_Editor[100];
    float M_Price;

public:
    void accept() {
        cout << "Enter Magazine name: ";
        cin.getline(M_Name, 100);
        cout << "Enter Editor's name: ";
        cin.getline(M_Editor, 100);
        cout << "Enter Price: ";
        cin >> M_Price;
        cin.ignore();  // Ignore newline char in the buffer
    }

    void display() const {
        cout << "Magazine Name: " << M_Name << endl;
        cout << "Editor: " << M_Editor << endl;
        cout << "Price: " << M_Price << endl;
    }
};

int main() {
    clrscr();
    NewsPaper newspaper;
    Magazine magazine;

    cout << "Enter details for a newspaper:\n";
    newspaper.accept();
    cout << "\nEnter details for a magazine:\n";
    magazine.accept();

    clrscr();  // Clear the screen before displaying results

    cout << "\nNewspaper Information:\n";
    newspaper.display();
    cout << "\nMagazine Information:\n";
    magazine.display();

    getch();
    return 0;
}
