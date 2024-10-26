// Program to convert time (hour, minute and second) in 24-hr format to 12-hr format.

#include<iostream>

using namespace std;


class TwentyFour{
    int hr, min, sec;

    public:
        TwentyFour(){}
        TwentyFour(int  h, int m, int s) : hr(h), min(m), sec(s){}        //constructor

        int getH(){
            return hr;
        }

        int getM(){
            return min;
        }
        
        int getS(){
            return sec;
        }

        void show(){
            cout << hr << ":" << min << ":" << sec << endl;
        }
};

class Twelve{
    int hr, min, sec;
    string Dayornight;

    public:
        Twelve(){}
        Twelve(int h, int m, int s) : hr(h), min(m), sec(s){}

        Twelve(TwentyFour &t){
            hr = t.getH() %12;
            min = t.getM();
            sec = t.getS();
            if (t.getH()>=12){
                Dayornight = "PM";
            } else {
                Dayornight = "AM";
            }
        }

        void show(){
            cout << hr << ":" << min << ":" << sec << " " << Dayornight<<endl;
        }
};

int main() {
    int hours, minutes, seconds;

   
    cout << "Enter hours (in 24-hour format): ";
    cin >> hours;

   
    cout << "Enter minutes: ";
    cin >> minutes;

    
    cout << "Enter seconds: ";
    cin >> seconds;

    // Creating TwentyFour object based on user input
    TwentyFour t24(hours, minutes, seconds);

    // Converting to Twelve-hour format
    Twelve t12 = t24;

    // Display both formats
    t24.show();
    t12.show();

    return 0;
}
/*
int main(){
    TwentyFour t24(7, 4, 6);
    Twelve t12;

    t12 = t24;

    t24.show();
    t12.show();

    return 0;
}
*/