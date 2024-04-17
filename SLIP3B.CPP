#include <iostream.h>
#include <fstream.h>
#include <stdlib.h>  // for atoi function

int main(int argc, char *argv[]) {
    ofstream evenFile, oddFile;

    // Open files for writing
    evenFile.open("Even.txt");
    oddFile.open("Odd.txt");

    // Process each command line argument
    for (int i = 1; i < argc; i++) {
        int num = atoi(argv[i]);  // Convert argument from char* to int
        if (num % 2 == 0) {
            evenFile << num << endl;  // Write to Even.txt if the number is even
        } else {
            oddFile << num << endl;  // Write to Odd.txt if the number is odd
        }
    }

    // Close file streams
    evenFile.close();
    oddFile.close();

    return 0;
}
