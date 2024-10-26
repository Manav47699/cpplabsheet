// Program to convert Polar Coordinate to Cartesian.

#include<iostream>
#include<cmath>

#define PI 3.141592

using namespace std;

class polar{
    float rad, ang;
    public:
        polar(float r, float a){            //constructor
            rad = r; 
            ang = PI * a / 180;             //converting angle to radian
        }

        float getRad(){
            return rad;
        }

        float getAng(){
            return ang;

        }
        
};

class cartesian{
    float x, y;
    public:
        cartesian(){}
        cartesian(polar p){
            float r = p.getRad();
            float a = p.getAng();
            x = r * cos(a);
            y = r * sin(a);
        }
        void show(){
            
            cout << "Cartasian coordinate: " << "X: " << x << "\tY: " << y;

            //cout << "X: " << x << "\tY: " << y;
        }
};

int main() {
    float radius, ang;

    
    cout << "Enter the radius (r): ";
    cin >> radius;

    
    cout << "Enter the angle in degrees (a): ";
    cin >> ang;


    polar p(radius, ang);                              // Creating polar object based on user input

    
    cartesian c;
    c=p;                                    // Create cartesian object using polar object

    
    cout << "Cartesian Coordinates:" << endl;
    
    c.show();
    cout << endl;

    return 0;
}








/*
int main(){
    polar p(5, 90);
    cartesian c;

    c = p;

    c.show();

    return 0;
}
*/