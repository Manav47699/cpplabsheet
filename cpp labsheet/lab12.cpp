//program to determine the minimum and  maximum among three numbers (using conditional operator)
#include <iostream> 
using namespace std;



int main(int argc, char const *argv[])
{
    int a, b, c;
    int maximum, minimum;
    cout <<"Enter the values of a b and c respectively";
    cin >> a >> b >> c;

    maximum = (a > b) ? ((a>c) ? a : c) : ((b>c) ? b : c);
    minimum = (a < b) ? ((a<c) ? a:c) : ((b<c) ? b : c);

    cout << "The maximum among the entered three numbers is " << maximum << " and the minimum among the three number is " << minimum;



    return 0;
}

