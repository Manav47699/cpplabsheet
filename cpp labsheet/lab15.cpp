#include <iostream>
#include <string.h>
using namespace std;

class Employee {
    static int countm;   
    static int counte;  
    int employee_id;
    string name;
    string designation;

public:
    void input() {
        cout << "Enter the ID, name, and designation (MANAGER or ENGINEER) of the employee:" << "\n";
        cin >> employee_id >> name >> designation;
    }

    void post() {
        if (designation == "MANAGER" ) {
            countm++;
        } else if (designation == "ENGINEER") {
            counte++;
        }
    }

     static void output() {
        cout << "Number of Managers: " << countm << "\n";
        cout << "Number of Engineers: " << counte << "\n";
        cout << "Total number of employees: " << countm + counte << "\n";
    }
};


int Employee::countm = 0;
int Employee::counte = 0;

int main() {
    int n;
    cout << "Enter the number of employees: ";
    cin >> n;

    Employee employees[n];

    for (int i = 0; i < n; ++i) {
        employees[i].input();
        employees[i].post();
    }
    /*if we print the output function using 
    for (int i = 0; i<n; ++i){
        employees[i].output
        }
        we should use "void output() insted of "static void output()" and the output will be printed the number of  'n' times*/

     Employee::output();

    return 0;
}
