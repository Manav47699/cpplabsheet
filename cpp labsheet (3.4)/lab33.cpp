// Program to convert Cartesian coordinate to Polar.
/*
#include<iostream>
#include<cmath>

using namespace std;

class polar{
    float rad, ang;

    public:
        polar(){}
        polar(float r, float a) : rad(r), ang(a){}

        void show(){
            cout << rad << ang;
        }
};

class cartesian{
    float x, y;
    public:
        cartesian(){}
        cartesian(float xco, float yco) : x(xco), y(yco){}

        operator polar(){
            float r = sqrt(x * x + y * y);
            float a = atan(y/x);

            return polar(r, a);
        }
};

int main() {
    float x, y;

    // Input x-coordinate
    cout << "Enter the x-coordinate: ";
    cin >> x;

    // Input y-coordinate
    cout << "Enter the y-coordinate: ";
    cin >> y;

    // Create cartesian object based on user input
    cartesian c(x, y);

    // Convert cartesian to polar
    polar p = c;

    // Display polar coordinates
    p.show();

    return 0;
}




/*
int main(){
    cartesian c(2, 3);
    polar p;

    p = c;
    p.show();
    return 0;
}
*/

#include <iostream>
#include <cmath>

#define PI 3.1415
using namespace std;

class coordinates {
    private:
    float x;
    float y;
    float r;
    float ang;
    public:
    coordinates (float xc, float yc) {
        x = xc;
        y = yc;

    }
    ~coordinates() {}
    void convert () {
        float a = pow (x,2) + pow (y,2);
        r = sqrt(a);
        ang = atan(y/x)*180 / PI;
    }
    void display () {
        cout << "Cartesian : << ("<<x<<" , "<<y<<")" << endl;
        cout << "polar coordinate : ("<<r<<" , "<<ang<<")";

    }
};

int main(int argc, char const *argv[])
{
    float x, y;
    cout << "ENter the cartesian coordinates:";
    cin >> x >> y;
    coordinates p (x,y);
    p.convert();
    p.display();
    return 0;
}
