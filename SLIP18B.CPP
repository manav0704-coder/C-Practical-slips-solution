#include <iostream.h>
#include <conio.h>

class MyArray {
private:
    int *arr;
    int size;

public:
    MyArray(int sz = 0) : size(sz) {
        arr = new int[size];
        for (int i = 0; i < size; i++) {
            arr[i] = 0;
        }
    }

    ~MyArray() {
        delete[] arr;
    }

    void accept() {
        cout << "Enter elements of the array:\n";
        for (int i = 0; i < size; i++) {
            cin >> arr[i];
        }
    }

    void display() const {
        cout << "Array elements are:\n";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    MyArray operator-() const {
        MyArray temp(size);
        for (int i = 0; i < size; i++) {
            temp.arr[i] = arr[size - 1 - i];
        }
        return temp;
    }

    MyArray operator+(int n) const {
        MyArray temp(size);
        for (int i = 0; i < size; i++) {
            temp.arr[i] = arr[i] + n;
        }
        return temp;
    }
};

int main() {
    clrscr();
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    MyArray A1(n), A2;
    A1.accept();
    A1.display();

    A2 = -A1;
    cout << "Reversed array elements are:\n";
    A2.display();

    cout << "Adding 5 to each element:\n";
    A2 = A1 + 5;
    A2.display();

    getch();
    return 0;
}
