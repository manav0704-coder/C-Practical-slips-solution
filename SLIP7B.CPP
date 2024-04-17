b) Create a C++ class Vector with data members size & pointer to integer. The size of the vector varies so the memory should be allocated dynamically.
Perform following operations:
i. Accept a vector
ii. Display a vector in the format (10, 20, 30,....)
111. Calculate union of two vectors.
(use parameterized constructor & copy constructor)
[Marks 25]

#include <iostream.h>
#include <conio.h>

class Vector {
private:
    int *p;
    int size;

public:
    // Parameterized constructor
    Vector(int sz) : size(sz) {
        p = new int[size];
    }

    // Copy constructor
    Vector(const Vector &v) {
        size = v.size;
        p = new int[size];
        for (int i = 0; i < size; i++) {
            p[i] = v.p[i];
        }
    }

    // Destructor
    ~Vector() {
        delete[] p;
    }

    // Accept vector elements from the user
    void accept() {
        cout << "Enter elements for the vector of size " << size << ":\n";
        for (int i = 0; i < size; i++) {
            cin >> p[i];
        }
    }

    // Display the vector in the format (10, 20, 30, ...)
    void display() {
        cout << "(";
        for (int i = 0; i < size; i++) {
            cout << p[i];
            if (i < size - 1) cout << ", ";
        }
        cout << ")";
    }

    // Static function to calculate the union of two vectors
    static Vector unionVectors(Vector &v1, Vector &v2) {
        // Temporary array to store union
        int temp[100]; // Adjust size as needed, assuming max 100 for demo
        int k = 0;
        for (int i = 0; i < v1.size; i++) {
            temp[k++] = v1.p[i];
        }
        for (int i = 0; i < v2.size; i++) {
            bool found = false;
            for (int j = 0; j < v1.size; j++) {
                if (v2.p[i] == v1.p[j]) {
		   int found = int true;
                    break;
                }
            }
            if (!found) {
                temp[k++] = v2.p[i];
            }
        }
        Vector result(k);
        for (int i = 0; i < k; i++) {
            result.p[i] = temp[i];
        }
        return result;
    }
};

void main() {
    clrscr();
    int size1, size2;
    cout << "Enter the size of the first vector: ";
    cin >> size1;
    Vector v1(size1);
    v1.accept();

    cout << "Enter the size of the second vector: ";
    cin >> size2;
    Vector v2(size2);
    v2.accept();

    cout << "Vector 1: ";
    v1.display();
    cout << "\nVector 2: ";
    v2.display();

    Vector vUnion = Vector::unionVectors(v1, v2);
    cout << "\nUnion of Vector 1 and Vector 2: ";
    vUnion.display();

    getch();
}
