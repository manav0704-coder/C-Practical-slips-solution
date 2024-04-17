b) Create a C++ class Time with data members Hours, Minutes and Seconds. Write necessary member functions for the following: (Use Objects as arguments)
i. To accept a time.
ii. To display a time in format hh:mm:ss.
iii. To find difference between two time and display it in format hh:mm:ss.
[Marks 25]

#include <iostream.h>
#include <conio.h>

class Time {
    int Hours;
    int Minutes;
    int Seconds;

public:
    void setTime(int h, int m, int s) {
        Hours = h;
        Minutes = m;
        Seconds = s;
    }

    void displayTime() {
        cout << (Hours < 10 ? "0" : "") << Hours << ":"
             << (Minutes < 10 ? "0" : "") << Minutes << ":"
             << (Seconds < 10 ? "0" : "") << Seconds << endl;
    }

    Time timeDifference(Time t2) {
        Time diff;
        int totalSec1 = Hours * 3600 + Minutes * 60 + Seconds;
        int totalSec2 = t2.Hours * 3600 + t2.Minutes * 60 + t2.Seconds;
        int totalDiff = totalSec1 - totalSec2;

        if (totalDiff < 0) {
            totalDiff = -totalDiff;
        }

        diff.Hours = totalDiff / 3600;
        totalDiff %= 3600;
        diff.Minutes = totalDiff / 60;
        diff.Seconds = totalDiff % 60;

        return diff;
    }
};

void main() {
    clrscr();

    Time t1, t2, diff;

    // Setting time for t1
    t1.setTime(10, 30, 30);
    // Setting time for t2
    t2.setTime(5, 45, 50);

    cout << "Time 1: ";
    t1.displayTime();
    cout << "Time 2: ";
    t2.displayTime();

    diff = t1.timeDifference(t2);
    cout << "Difference: ";
    diff.displayTime();

    getch();
}
