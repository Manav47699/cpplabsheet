//Write a program to convert cartisian plan to polar form

#include <iostream>
#include <cmath>

using namespace std;

class Cartisain
{
    float x; float y;
    public:
    Cartisain(float a, float b)
    {
        x = a;
        y = b;
    }
    float getx()
    {
        return x;
    }
    float gety()
    {
        return y;
    }


};

class Polar
{
    float rad; float ang;
    public:
    Polar (Cartisain &c)
    {
        float tot_x = c.getx();
        float tot_y = c.gety();
        rad = (tot_x*tot_x + tot_y * tot_y);
        ang = atan2(tot_x, tot_y);
    }
    void show()
    {
        cout << "radian = " << rad << endl << "angle = " << ang << endl;
    }

};

int main(int argc, char const *argv[])
{
    Cartisain c(5.65, 7.86);
    Polar p(c);
    p.show();
    return 0;
}

