//function template
#include <iostream>
using namespace std;

template <class T>
T sum (T a, T b)
{
    T divide;
    divide = a+b;
    return divide;
}

int main(int argc, char const *argv[])
{
    int a, b;
    cin >> a >> b;
    cout << sum<int>(a, b);
    
    return 0;
}
