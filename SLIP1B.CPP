#include <iostream.h>
#include <fstream.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

class MyFile {
private:
    fstream file;
    char filename[100];

public:
    MyFile(const char* fname) {
        strcpy(filename, fname);
        file.open(filename, ios::in | ios::out | ios::ate); // Open for input and output, move to the end.
        if (!file.good()) {
            cerr << "Failed to open file: " << filename << endl;
            file.clear();
        }
    }

    ~MyFile() {
        if (file.is_open()) {
            file.close();
        }
    }

    void display() {
        if (file.is_open()) {
            file.seekg(0, ios::beg); // Reset file pointer to the beginning for reading
            char line[255];
            while (file.getline(line, 255)) {
                cout << line << endl;
            }
            file.clear(); // Clear EOF flag to allow further operations
        }
    }

    MyFile operator+(const MyFile& other) {
        char newFileName[120] = "Concatenated_";
        strcat(newFileName, filename);
        MyFile resultFile(newFileName);

        // Ensure file is open and clear before writing
        if (!resultFile.file) {
            cerr << "Unable to open file: " << newFileName << endl;
            return resultFile;
        }

        file.seekg(0, ios::beg);
        char content[255];
        while (file.getline(content, 255)) {
            resultFile.file << content << '\n';
        }

        fstream tempFile(other.filename, ios::in);
        if (!tempFile) {
            cerr << "Failed to open file: " << other.filename << endl;
            return resultFile;
        }

        char otherContent[255];
        while (tempFile.getline(otherContent, 255)) {
            resultFile.file << otherContent << '\n';
        }
        tempFile.close();

        return resultFile;
    }

    MyFile& operator!() {
        char tempFileName[] = "temp.txt";
        fstream tempFile(tempFileName, ios::out);
        if (!tempFile) {
            cerr << "Unable to open temporary file." << endl;
            return *this;
        }

        file.seekg(0, ios::beg);
        char ch;
        bool toggle = true;
        while (file.get(ch)) {
            if (toggle) {
                if (ch >= 'a' && ch <= 'z') {
                    ch -= 32;
                }
            } else {
                if (ch >= 'A' && ch <= 'Z') {
                    ch += 32;
                }
            }
            tempFile.put(ch);
            toggle = !toggle;
        }
        file.close();
        tempFile.close();

        // Replace original file with modified content
        file.open(filename, ios::in | ios::out | ios::trunc);
        tempFile.open(tempFileName, ios::in);
        while (tempFile.get(ch)) {
            file.put(ch);
        }
        file.clear();
        tempFile.close();
        remove(tempFileName);

        return *this;
    }
};

int main() {
    clrscr();
    MyFile f1("file1.txt");
    MyFile f2("file2.txt");

    MyFile f3 = f1 + f2;
    cout << "Contents of F3 after concatenation:" << endl;
    f3.display();

    !f3;
    cout << "Contents of F3 after toggling case:" << endl;
    f3.display();

    getch();
    return 0;
}
