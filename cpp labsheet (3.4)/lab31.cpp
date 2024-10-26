#include<iostream>
#include <iomanip>
using namespace std;

class Rupees {
    int rupee, paisa;

public:
    Rupees(int ru, int pa) {                 //constructor
        rupee = ru;
        paisa = pa;
    }

    void show() {
        cout << "Rs." << rupee << "." << paisa;
    }

    int getRupees() const {
        return rupee;
    }

    int getPaisa() const {
        return paisa;
    }
};

class Dollars {
    int dollar, cent;

public:
    Dollars( Rupees r) {
        float totalRupees = r.getRupees() + (float)(r.getPaisa()) / 100.0;
        float totalDollars = totalRupees / 98.51;
        dollar = (int)(totalDollars);
        cent = (int)((totalDollars - dollar) * 100);
    }

    void show() {
        cout << "$" << dollar << "." << cent;
    }
};
/*
class Dollars {
    int dollar, cent;

public:
    Dollars(const Rupees& r) {
        float totalRupees = r.getRupees() + (float)(r.getPaisa()) / 100.0;
        float totalDollars = totalRupees / 98.51;                                      // Ensure this conversion rate is accurate
        dollar = (int)(totalDollars);
        cent = (int)((totalDollars - dollar) * 100);
    }

    void show() const {
        cout << "$" << dollar << "." << setw(2) << setfill('0') << cent;
    }
};
*/
int main() {
    int rupee, paisa;

    cout << "Enter the amount of rupees: ";
    cin >> rupee;
    cout << "Enter the amount of paisa: ";
    cin >> paisa;

    Rupees r(rupee, paisa);
    Dollars d(r);

    cout << "Amount in Nepalese Currency: ";
    r.show();
    cout << endl;

    cout << "Equivalent in US Currency: ";
    d.show();
    cout << endl;

    return 0;
}