#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    int x;

    cout << "Enter the number: ";
    cin >> x;

    try {
        try {
            if (x == 0) {
                throw x; // Throwing an exception for zero input
            } else {
                cout << "The number is: " << x << endl;
            }
        } catch (int i) { // Catch block for the integer exception
            cout << "Exception caught: You cannot enter zero!" << endl;
            throw; // Rethrowing the exception
        }
    } catch (...) { // Catching rethrown exceptions
        cout << "Exception caught outside the try block" << endl;
    }

    return 0;
}
