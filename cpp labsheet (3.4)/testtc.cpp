///*Write a program to read a height of a
//person in Feet and Inches and convert it floato Meter using class type to class type
//conversion method. (1 meter= 3.28084 feet, 1 feet=12 inch.)*/
#include <iostream>
#include <cmath>
using namespace std;

class H1
{
    float feet; float inches;
    public:
    H1(float f, float i)
    {
        feet = f;
        inches = i;

    }
    void display ()
    {
        cout << feet << endl << inches;

    }
    float getfeet()
    {
        return feet;
    }
    float getinches()
    {
        return inches;
    }
};

class H2
{
    float meter;
    public:
    H2()
    {
        meter = 0;
    }
    H2 (H1 &h)
    {
        float total_inches = h.getinches();
        float total_feet = h.getfeet() + total_inches/12;
        meter = total_feet/3.280;

    }
    void display ()
    {
        cout << "total distance in meter= " << meter;
    }

};

int main(int argc, char const *argv[])
{
    H1 h1(5, 4);
    H2 h2(h1);
    h2.display();
    return 0;
}


