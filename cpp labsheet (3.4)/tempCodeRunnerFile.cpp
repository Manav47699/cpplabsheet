#include <iostream>
using namespace std;

class Ran
{
    const int c1;
    static int c2;
    public:
    Ran () : c1(0)
    {
        
        c2=0;
    }
    void display()
    {
        cout << c1++ << endl << c2++;
    }

};

int Ran:: c2 =0;

int main(int argc, char const *argv[])
{
    Ran r1;
    r1.display();
    r1.display();
    
    return 0;
}
