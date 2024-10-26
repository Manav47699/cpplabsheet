// Write a program to demonstrate exception handling with “catch all” block.

#include<iostream>
using namespace std;

int main()
{
    try {
        float x, y;

        cout << "Enter x: ";
        cin >> x;

        cout << "Enter y: ";
        cin >> y;

        if(y == 0) {
            throw runtime_error("Division by zero is not allowed");
        }

        float division = x/y;

        cout << "Division result: " << division << endl;
       } 
       
       catch (runtime_error& e) {
        cout << "Runtime error: " << e.what() << endl;
        }

        catch (...) {
        cout << "An unknown exception occurred." << endl;
       }

        return 0;
}