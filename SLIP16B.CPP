#include <iostream.h>
#include <conio.h>

class MyMatrix {
private:
    int **data;
    int rows, cols;

public:
    MyMatrix(int r, int c) : rows(r), cols(c) {
        data = new int*[rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new int[cols];
        }
    }

    ~MyMatrix() {
        for (int i = 0; i < rows; i++) {
            delete[] data[i];
        }
        delete[] data;
    }

    void accept() {
        cout << "Enter matrix elements:\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cin >> data[i][j];
            }
        }
    }

    void display() const {
        cout << "Matrix:\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }

    MyMatrix operator-() const {
        MyMatrix trans(cols, rows);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                trans.data[j][i] = data[i][j];
            }
        }
        return trans;
    }

    MyMatrix& operator++() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                ++data[i][j];
            }
        }
        return *this;
    }
};

int main() {
    clrscr();
    int r, c;
    cout << "Enter number of rows and columns: ";
    cin >> r >> c;

    MyMatrix m(r, c);
    m.accept();
    m.display();

    cout << "Matrix Transpose:\n";
    MyMatrix mT = -m;
    mT.display();

    cout << "Incrementing matrix elements by 1:\n";
    ++m;
    m.display();

    getch();
    return 0;
}
