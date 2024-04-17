b) Create a C++ class
class Matrix
{
int **p;
int r, c;
public:
//member functions
};
Write necessary member functions to:
i. Accept Matrix elements
11. Display Matrix elements.
iii. Calculate transpose of a Matrix. (Use constructor and destructor)
[Marks 25]

#include <iostream.h>
#include <conio.h>  // Include for Turbo C++ console input/output

class Matrix {
    int **p;  // Pointer to matrix data
    int r, c; // Rows and columns

public:
    // Constructor
    Matrix(int rows, int cols) : r(rows), c(cols) {
        p = new int*[r];
        for (int i = 0; i < r; ++i) {
            p[i] = new int[c];
        }
    }

    // Destructor
    ~Matrix() {
        for (int i = 0; i < r; ++i) {
            delete[] p[i];
        }
        delete[] p;
    }

    // Accept matrix elements
    void accept() {
        cout << "Enter matrix elements row by row:\n";
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                cout << "Element [" << i + 1 << "][" << j + 1 << "]: ";
                cin >> p[i][j];
            }
        }
    }

    // Display matrix elements
    void display() const {
        cout << "Matrix:\n";
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                cout << p[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Calculate and return transpose of the matrix
    Matrix transpose() const {
        Matrix t(c, r); // Transpose will have flipped dimensions
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                t.p[j][i] = p[i][j];
            }
        }
        return t;
    }
};

void main() {
    clrscr();
    int rows, cols;
    cout << "Enter the number of rows and columns for the matrix: ";
    cin >> rows >> cols;

    Matrix m(rows, cols);
    m.accept();
    m.display();

    Matrix mTranspose = m.transpose();
    cout << "Transpose of the Matrix:\n";
    mTranspose.display();

    getch();  // Wait for a key press
}
