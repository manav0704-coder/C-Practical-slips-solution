#include <iostream.h>
#include <conio.h>

class MyMatrix {
private:
    int **data;
    int rows, cols;

public:
    // Constructor to initialize the matrix of given size
    MyMatrix(int r, int c) : rows(r), cols(c) {
        data = new int*[rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new int[cols];
        }
    }

    // Destructor to deallocate memory
    ~MyMatrix() {
        for (int i = 0; i < rows; i++) {
            delete[] data[i];
        }
        delete[] data;
    }

    // Function to accept matrix data from user
    void accept() {
        cout << "Enter matrix elements (" << rows << "x" << cols << "):\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cin >> data[i][j];
            }
        }
    }

    // Function to display the matrix
    void display() {
        cout << "Matrix:\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Overload binary '-' operator to perform matrix subtraction
    MyMatrix operator-(const MyMatrix &other) {
        // Assuming matrices have the same dimensions
        MyMatrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.data[i][j] = data[i][j] - other.data[i][j];
            }
        }
        return result;
    }
};

int main() {
    clrscr();
    int rows, cols;
    cout << "Enter the number of rows and columns for the matrices: ";
    cin >> rows >> cols;

    MyMatrix matrix1(rows, cols), matrix2(rows, cols);
    cout << "\nEnter data for first matrix:\n";
    matrix1.accept();
    cout << "\nEnter data for second matrix:\n";
    matrix2.accept();

    cout << "\nFirst Matrix:\n";
    matrix1.display();

    cout << "\nSecond Matrix:\n";
    matrix2.display();

    MyMatrix result = matrix1 - matrix2;
    cout << "\nResult of Matrix Subtraction:\n";
    result.display();

    getch();
    return 0;
}
