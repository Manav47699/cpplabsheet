//A friend class can access private and protected members of other classes in which
// it is declared as a friend. It is sometimes useful to allow a particular class to 
// access private and protected members of other classes.
#include <iostream>
using namespace std;

class Datas {
private:
    int a, b;
public:
    void input() {
        cout << "Enter the two numbers 'a' and 'b' respectively: ";
        cin >> a >> b;
    }

    friend void swap(Datas &data);                                 // Friend function declaration

    void output() {
        cout << "a = " << a << " and b = " << b << endl;
    }
};


void swap(Datas &data) {                                          // Friend function definition 
    int temp = data.a;
    data.a = data.b;
    data.b = temp;
}

int main() {
    Datas data;
    data.input();
    swap(data);                                                   // Calling swap 
    cout << "After swapping: ";
    data.output();
    return 0;
}


/* 
#include <iostream>
using namespace std;

class B;

class A 
{
    int data1;
    public:
    A(int a)
    {
        data1 =a;
        
    }
    friend void swap( A &a, B &b);
    
};

class B 
{
    int data2;
    public:
    B(int b)
    {
        data2 =b;
        
    }
    friend void swap(A &a,B &b);
};
 void swap (A &a,B &b)
{
    int temp;
    temp = a.data1;
    a.data1 = b.data2;
    b.data2= temp;
    cout << "a= " << a.data1 << endl << "b= " << b.data2 << endl;
}

int main ()
{
    A a(5);
    B b(3);
    swap(a , b);
    return 0;
}

*/