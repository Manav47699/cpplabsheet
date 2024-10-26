#include <iostream>
using namespace std;

class Time
{
    int min , hrs;
    public:
    Time ()
    {
        min = 0;
        hrs=0;
    }
    friend istream & operator >> (istream &, Time &);
    friend ostream & operator << (ostream &, Time &);


};

istream & operator >> (istream & input , Time & t)
{
    input >> t.min >> t.hrs;
}
ostream & operator << (ostream & output, Time & t)
{
    output << t.min << endl << t.hrs;

}

int main(int argc, char const *argv[])
{
    Time t1;
    cin >> t1;
    cout << t1;
    return 0;
}


/*
#include <iostream>
using namespace std;


class Time {
private:
    int hours;
    int minutes;

public:
    Time() : hours(0), minutes(0) {}

    // Overloading >> for input
    friend istream& operator>>(istream& in, Time& t); //Declared the Friend Function Since operator>> will need access to the private members of MATRIX

    // Overloading << for output
    friend ostream& operator<<(ostream& out, const Time& t);
};

// Overloading >> for input
istream& operator>>(istream& in, Time& t) {
    cout << "Enter hours: ";
    cin >> t.hours;
    cout << "Enter minutes: ";
    cin >> t.minutes;
    return in;
};

// Overloading << for output
ostream& operator<<(ostream& out, const Time& t) {
    out << t.hours << " hours " << t.minutes << " minutes";
    return out;
}

int main() {
    Time t1, t2;

    
    cout << "Enter Time 1:" << std::endl;
    cin >> t1;

    cout << "Enter Time 2:" << std::endl;
    cin >> t2;

    
    cout << "Time 1: " << t1 << std::endl;
    cout << "Time 2: " << t2 << std::endl;

    return 0;
}

/*
#include <iostream>

using namespace std;

class TIME {
private:
    int hours;
    int minutes;
    int seconds;

public:

    TIME() : hours(0), minutes(0), seconds(0) {}

    TIME(int h, int m, int s) : hours(h), minutes(m), seconds(s) {}

    friend istream& operator>>(istream& input, TIME& t) {
        cout << "Enter hours: ";
        input >> t.hours;
        cout << "Enter minutes: ";
        input >> t.minutes;
        cout << "Enter seconds: ";
        input >> t.seconds;
        return input;
    }
    friend ostream& operator<<(ostream& output, const TIME& t) {
        output << (t.hours < 10 ? "0" : "") << t.hours << ":"
               << (t.minutes < 10 ? "0" : "") << t.minutes << ":"
               << (t.seconds < 10 ? "0" : "") << t.seconds;
        return output;
    }
};

int main() {
    TIME t1;
    cout << "Input time:" << endl;
    cin >> t1;
    cout << "The time entered is: " << t1 << endl;
    return 0;
}
*/