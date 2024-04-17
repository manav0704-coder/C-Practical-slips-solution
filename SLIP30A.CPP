#include <iostream.h>
#include <conio.h>

class Float_Array; // Forward declaration for friend function declaration

class Integer_Array {
    int *arr;
    int size;
public:
    Integer_Array(int sz) : size(sz) { arr = new int[size]; }
    ~Integer_Array() { delete[] arr; }
    void accept();
    void display();
    friend void displayAverages(Integer_Array&, Float_Array&);
};

class Float_Array {
    float *arr;
    int size;
public:
    Float_Array(int sz) : size(sz) { arr = new float[size]; }
    ~Float_Array() { delete[] arr; }
    void accept();
    void display();
    friend void displayAverages(Integer_Array&, Float_Array&);
};

void Integer_Array::accept() {
    cout << "Enter integer array elements:\n";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

void Integer_Array::display() {
    cout << "Integer array elements:\n";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void Float_Array::accept() {
    cout << "Enter float array elements:\n";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

void Float_Array::display() {
    cout << "Float array elements:\n";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void displayAverages(Integer_Array& ia, Float_Array& fa) {
    int sumInt = 0;
    float sumFloat = 0.0;

    for (int i = 0; i < ia.size; i++) {
        sumInt += ia.arr[i];
    }
    for (int i = 0; i < fa.size; i++) {
        sumFloat += fa.arr[i];
    }

    cout << "Average of Integer Array: " << (float)sumInt / ia.size << endl;
    cout << "Average of Float Array: " << sumFloat / fa.size << endl;
}

int main() {
    clrscr();

    Integer_Array ia(5);
    Float_Array fa(5);

    ia.accept();
    fa.accept();

    ia.display();
    fa.display();

    displayAverages(ia, fa);

    getch();
    return 0;
}
