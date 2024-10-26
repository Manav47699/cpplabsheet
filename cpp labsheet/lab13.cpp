#include <iostream>
using namespace std;

int main() {
    int order, store;

    cout << "Enter the order quantity and store quantity resp. ";
    cin >> order >> store;
     
    if (order > store) {
        cout << "Not enough quantity. \n";
    }
    
    else {
        if (store <= 40 && order >16) {
            cout << "You cannot order more than 16 items.\n";
        } else {
            cout << "Your order is accepted.\n";
        }
    }

    return 0;
}
    
