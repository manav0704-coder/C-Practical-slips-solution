b) Write a C++ program to read the contents of a "SampleData.txt" file. Create "Upper.txt" file to store uppercase characters, "Lower.txt" file to store lowercase characters, "Digit.txt" file to store digits and "Other.txt" file to store remaining characters of a given file.
[Marks 25]

#include <fstream.h>   // File stream
#include <conio.h>     // For clrscr(), getch()
#include <ctype.h>     // For character checking functions

int main() {
    clrscr();
    char ch;

    // Open input file
    ifstream inFile("SampleData.txt");
    if (!inFile) {
        cout << "Cannot open input file. Program terminating.\n";
        getch();
        return 1;
    }

    // Create output files
    ofstream upperFile("Upper.txt");
    ofstream lowerFile("Lower.txt");
    ofstream digitFile("Digit.txt");
    ofstream otherFile("Other.txt");

    // Read characters from the input file and categorize them
    while (inFile.get(ch)) {
        if (isupper(ch))
            upperFile << ch;
        else if (islower(ch))
            lowerFile << ch;
        else if (isdigit(ch))
            digitFile << ch;
        else
            otherFile << ch;
    }

    // Close all files
    inFile.close();
    upperFile.close();
    lowerFile.close();
    digitFile.close();
    otherFile.close();

    cout << "File categorization complete.";
    getch();
    return 0;
}
