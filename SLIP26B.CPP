#include <iostream.h>
#include <conio.h>

class Time {
private:
    int hours, minutes, seconds;

public:
    Time() : hours(0), minutes(0), seconds(0) {} // Default constructor

    // Overload ! to check if two times are not equal
    int operator !() {
        return hours == 0 && minutes == 0 && seconds == 0;
    }

    // Friend function to overload >> operator to input time
    friend istream& operator>>(istream& in, Time& t) {
        cout << "Enter hours, minutes, seconds: ";
        in >> t.hours >> t.minutes >> t.seconds;
        return in;
    }

    // Friend function to overload << operator to output time
    friend ostream& operator<<(ostream& out, Time& t) {
        out << t.hours << " hrs, " << t.minutes << " mins, " << t.seconds << " secs";
        return out;
    }

    // Function to check if two times are equal using ! operator
    int operator ==(Time& t) {
        return (hours == t.hours && minutes == t.minutes && seconds == t.seconds) ? 1 : 0;
    }
};

int main() {
    clrscr();
    Time t1, t2;

    cout << "Enter first time:" << endl;
    cin >> t1;
    cout << "Enter second time:" << endl;
    cin >> t2;

    cout << "First time: " << t1 << endl;
    cout << "Second time: " << t2 << endl;

    if (t1 == t2)
        cout << "Both times are equal." << endl;
    else
        cout << "Times are not equal." << endl;

    getch();
    return 0;
}
