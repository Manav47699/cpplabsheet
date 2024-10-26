//A code to add two distance given in feet and inches
#include <iostream>
using namespace std;

class DISTANCE
{
    private:
    int feet1;
    int inches1;
    int feet2, inches2;
    int sumfeet, suminches;

    public:
    void input(){
        cout << "Enter the first distance in feet and inch resp." << "\n";
        cin >> feet1 >> inches1;
        cout << "Enter the second distance";
        cin >> feet2 >> inches2;
    }
    
    void show_input (){
        cout << feet1 << "\n" << inches1 << "\n" << feet2 << "\n" << inches2;
    }

    void add () {
        sumfeet = feet1 + feet2;
        suminches = inches1 + inches2;
        if (suminches >=12)
        {
            sumfeet++;
            suminches = suminches - 12;

        }
        cout << "The total distance is " << sumfeet << "feets and " << suminches << "inches";
    }


};

int main(int argc, char const *argv[])
{
    DISTANCE distance;
    distance.input();
    distance.show_input();
    distance.add();
    return 0;
}
