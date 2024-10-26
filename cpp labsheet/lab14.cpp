// wrong
#include <iostream>
using namespace std;

class EMPLOYEE
{
 
    int emp_no;
    char emp_name[100];
    float basic;
    float da;
    float net, it;
    
    public:
    void input (){
        cout <<"\n" <<"Enter the emoployee number, name, basic salary resp.";
        cin >> emp_no >> emp_name >> basic;
    }

    void show_input () {
        cout << emp_no << '\n' << emp_name << '\n' << basic << '\n';
    }
    void calculate() {
    da = 0.52* basic;
    float gross = basic + da;
    it = 0.3* gross;
    net = gross - it;
    cout << net;
    };
};

/*void EMPLOYEE:: calculate(){
    da = 0.52* basic;
    float gross = basic + da;
    it = 0.3* gross;
    net = gross - it;
    cout << net;
}
*/

int main(int argc, char const *argv[])
{
    EMPLOYEE E[100];
    int n;
    cout << "Enter the number of emoployees";
    cin >> n;
    for (int i = 0; i<n ; i++)
    {
        E[i].input();
        E[i].calculate();
    }
    for (int i = 0; i<n; i++)
    {
        E[i].show_input();
    }
    for (int i = 0; i<n; i++)
    {
        E[i].calculate();
    }

    return 0;
}
