#include <iostream>
#include <cstring>
using namespace std;
class Person

{
    char name[30];
    int age;
    public:
    Person (char* n, int a)
    {
        strncpy(name, n , sizeof(name)-1);
        age = a;
    }

    void display()
    {
        cout << "Name" << name << endl << age;
    }


};
class Employee:public Person
{
    protected:
    
    char degi[30];
    int bs, time, rate, cs;
    public:
    Employee (char* n, int a, char*d, int b, int t, int r): Person (n, a)
    {
        strncpy(degi, d, sizeof(degi)-1);
        bs = b;
        time = t;
        rate = r;
        //cs = c;
    }
    int calculation ()
    {
        cs = bs + time*rate;
        return cs;
    }
    void display()
    {
        Person::display();
        cout << "degination: " << degi <<endl << "cs= " << cs;

    }

 
};
int main(int argc, char const *argv[])
{
    Employee e("manav", 21, "Manager", 100000, 12, 4);
    e.calculation();
    e.display();

    return 0;
}



/*
#include <iostream>
#include <cstring> 

using namespace std;

class Person {
protected:
    char name[30];
    int age;
    int id;

public:
    
    void getData() {
        cout << "Enter name: ";
        cin.ignore();                                                  // Ignore leftover newline from previous input
        cin.getline(name, 30);
        cout << "Enter age: ";
        cin >> age;
        cout << "Enter ID: ";
        cin >> id;
    }

    
    void showData() const {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "ID: " << id << endl;
    }
};

class Employee : public Person {
protected:
    char designation[30];
    float basicSal;
    int totOvertime;
    int hourlyRate;

public:
    
    void getData() {
        Person::getData();
        cout << "Enter employee designation: ";
        cin.ignore();                                        // Ignore leftover newline from previous input
        cin.getline(designation, 30);
        cout << "Enter basic salary: ";
        cin >> basicSal;
        cout << "Enter total overtime in hours: ";
        cin >> totOvertime;
        cout << "Enter hourly rate: ";
        cin >> hourlyRate;
    }

    
    void showData() const {
        Person::showData();
        cout << "Designation: " << designation << endl;
        cout << "Basic Salary: " << basicSal << endl;
    }
};

class ComputedSalary : public Employee {
private:
    float totalSal;

public:

    void getData() {
        Employee::getData();
        calculate();
    }


    void calculate() {
        totalSal = basicSal + (totOvertime * hourlyRate);
    }


    float getTotal() const {
        return totalSal;
    }


    void showData() const {
        Employee::showData();
        cout << "Total Salary: " << totalSal << endl;
    }
};

int main() {
    ComputedSalary total;
    total.getData();
    total.showData();
    return 0;
}
*/