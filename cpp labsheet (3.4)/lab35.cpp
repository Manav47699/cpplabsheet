// Program to convert time (hour, minute and second) in 12-hr format to 24-hr format.

#include <iostream>
#include <string>

using namespace std;

class TwentyFour;

class Twelve
{
    int hr, min, sec;
    string DayorNight;

public:
    Twelve() {}
    Twelve(int h, int m, int s, string meridian) : hr(h), min(m), sec(s), DayorNight(meridian) {}                  //constructor       

    operator TwentyFour();

    void show()
    {
        cout << hr << ":" << min << ":" << sec << " " << DayorNight << endl;
    }
};

class TwentyFour
{
    int hr, min, sec;

public:
    TwentyFour() {}
    TwentyFour(int h, int m, int s) : hr(h), min(m), sec(s) {}

    int getH()
    {
        return hr;
    }

    int getM()
    {
        return min;
    }

    int getS()
    {
        return sec;
    }

    void show()
    {
        cout << hr << ":" << min << ":" << sec << endl;
    }
};

Twelve::operator TwentyFour()
{
    if (DayorNight == "AM")
    {
        return TwentyFour(hr, min, sec);
    }
    else
    {
        if (hr == 12)
        {
            return TwentyFour(hr, min, sec);
        }
        else
        {
            return TwentyFour(hr + 12, min, sec);
        }
    }
}

int main() {
    int hours, minutes, seconds;
    string DayorNight;

    // Input hours
    cout << "Enter hours (in 12-hour format): ";
    cin >> hours;

    // Input minutes
    cout << "Enter minutes: ";
    cin >> minutes;

    // Input seconds
    cout << "Enter seconds: ";
    cin >> seconds;

    // Input meridian (AM/PM)
    cout << "Enter (AM/PM): ";
    cin >> DayorNight;

    // Create Twelve object based on user input
    Twelve t12(hours, minutes, seconds, DayorNight);

    // Convert to TwentyFour-hour format
    TwentyFour t24 = t12;

    // Display both formats
    t12.show();
    t24.show();

    return 0;
}



/*
int main()
{
    TwentyFour t24;
    Twelve t12(7, 8, 9, "PM");

    t24 = t12;

    t12.show();
    t24.show();

    return 0;
}
*/