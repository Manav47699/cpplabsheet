//exception handelling catch all and rethrowing
#include <iostream>
using namespace std;

class Divide
{
    int a, b;
    public:
    Divide ()
    {
        a = 0;
        b=0;
    }
    Divide (int x, int y)
    {
        a = x;
        b = y;
    }

    void check()
   
    {
        if (b==0)
        {
            throw b;
        }
        else if (b<0)
        {
            throw 1.1f;
        }
        else
        {
            cout << "sum= " << a/b;
        }

        
    }
/*
  {
    try
    {
        if (b==0)
        {
            throw b;
        }
    }
    catch(int i)
    {
        cout << "rethrowing it";
        throw b;
    }
    
}
*/
};
int main()
{
    int a, b;
    cout <<"Enter a and b";
    cin >> a >> b;
    Divide d(a, b);
    try
    {
        d.check();
    }
    
    catch(float f)
    {
        cout <<"b cant do zero";
        
    }
    catch(int e)
    {
        cout << "b cant be zero";
    }

}