//using function template to add two arrays
#include <iostream>
using namespace std;

template <class T>
T sumnavg(T a[], T n)
{
    
   
    T sum, avg;
    for (int i = 0; i < n; i++)
    {
        sum = sum + a[i];
        
    }
    avg = sum/n;
    cout << "sum= "<< sum << "and average= " << avg;
    return 0;
    
}

int main(int argc, char const *argv[])
{
    int n;
    cout << "enter the value of n";
    cin >> n;
    int* arr= new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        
    }
    
    sumnavg(arr, n);
    

    return 0;
}
