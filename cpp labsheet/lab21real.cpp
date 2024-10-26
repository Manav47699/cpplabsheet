//a program to swap two private values using a friend function
#include <iostream>

using namespace std;

///void swap ();

class Datas
{
    private:
    int a, b;
    public:
    void input() {
        cout << "Enter the two number 'a' and 'b' respectively.";
        cin >> a >> b;
    }
    friend void swap (Datas &data); // ya freind + returntype + function_name lekhne
    ///Tio bracket bhitra ko kura haru hera

    void output() {
        cout << "a= " << a << "and b= " << b;
    }
};

void swap (int a, int b) 
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}



int main(int argc, char const *argv[])
{
    Datas data;
    data.input();
    data.swap();
    data.output();
    return 0;
}
