
#include <iostream>
using namespace std;

class Time
{
    int hrs, min, sec;
    public:
    Time()
    {
        hrs = 0; min=0; sec=0;
    }
    Time (int h, int m, int s)
    {
        hrs = h; min = m; sec = s;
    }

    Time operator + (Time o)
    {
        Time temp;
        temp.sec = sec + o.sec;
        temp.min = min + o.min + temp.sec/60;
        temp.sec = temp.sec%60;
        temp.hrs = hrs + o.hrs + temp.min/60;
        temp.min = temp.min%60;

        return temp;

    }
    /*
    bool operator < (Time o)
    {
        if (hrs> o.hrs)
        {
            return true;
        }
        else{
            return false;
        }
        return sec > o.sec;
    }
*/

    int operator < (Time t)
    {
        int ft, st;
        ft = hrs * 60 * 60 + min *60 + sec;
        st = t.hrs * 60 * 60 + t.min * 60 + t.sec;
        if (ft<st)
        {
            return 1;
           
            
        }
         else
            return 0;
        
    }



    
    void display()
    {
        cout << hrs << endl << min << endl << sec << endl;
    }

};
int main(int argc, char const *argv[])
{
    Time t1(2,3,4);
    Time t2(1,1,1);
    Time t3 = t1+t2;
    t3.display();
    if (t1<t2)
        {
            cout <<"1st time is greater";
           
            
        }
         else
            cout << "Second time is greater";
    

    

    return 0;
}















/*
#include <iostream>
#include <iomanip>

using namespace std;

class TIME {
private:
    int hours;
    int minutes;
    int seconds;

public:

    TIME() : hours(0), minutes(0), seconds(0) {}                 //constructor to initialize the object to zero

    TIME(int h, int m, int s) : hours(h), minutes(m), seconds(s) {      // constructor to initialize the object to some constant value
       // normalize();   
    }

    void conversion() {
        if (seconds >= 60) {
            //minutes += seconds / 60;
            //seconds %= 60;
            seconds = seconds - 60;
            minutes =+1;
        }
        if (minutes >= 60) {
            //hours += minutes / 60;
            //minutes %= 60;
            minutes = minutes - 60;
            hours = hours + 1;
        }
    }

    TIME operator+(const TIME& other) const {
        return TIME(hours + other.hours, minutes + other.minutes, seconds + other.seconds);
    }

    TIME operator-(const TIME& other) const {
        int h = hours - other.hours;
        int m = minutes - other.minutes;
        int s = seconds - other.seconds;
        if (s < 0) {
            s += 60;
            m -= 1;
        }
        if (m < 0) {
            m += 60;
            h -= 1;
        }
        return TIME(h, m, s);
    }
    bool operator>(const TIME& other) const {
        if (hours > other.hours) return true;
        if (hours < other.hours) return false;
        if (minutes > other.minutes) return true;
        if (minutes < other.minutes) return false;
        return seconds > other.seconds;
    }
    void display() const {
        cout << setfill('0') << setw(2) << hours << ":"
             << setfill('0') << setw(2) << minutes << ":"
             << setfill('0') << setw(2) << seconds << endl;
    }
};

int main() {
    TIME t1(2, 45, 30);
    TIME t2(1, 20, 45);
    
    TIME sum = t1 + t2;
    TIME difference = t1 - t2;

    cout << "Time 1: ";
    t1.display();
    cout << "Time 2: ";
    t2.display();
    cout << "Sum: ";
    sum.display();
    cout << "Difference: ";
    difference.display();
    
    if (t1 > t2) {
        cout << "Time 1 is greater than Time 2" << endl;
    } else {
        cout << "Time 1 is not greater than Time 2" << endl;
    }

    return 0;
}

*/