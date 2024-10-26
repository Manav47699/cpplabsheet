#include <iostream>
#include <iomanip>

using namespace std;

class Dollars;                                                                             // Forward declaration

class Rupees {
    float amount;

public:
    
    Rupees(float amt) : amount(amt) {}                                                         //Constructor

    
    void show() {
        cout << fixed << setprecision(2) << amount << " NPR";                          // Method to display amount
    } 

    // Friend function declarations for operator overloading
    friend bool operator>(const Rupees& r, const Dollars& d);
    friend bool operator<(const Rupees& r, const Dollars& d);
    friend bool operator>=(const Rupees& r, const Dollars& d);
    friend bool operator<=(const Rupees& r, const Dollars& d);
    friend bool operator==(const Rupees& r, const Dollars& d);
    friend bool operator!=(const Rupees& r, const Dollars& d);

    friend bool operator>(const Dollars& d, const Rupees& r);
    friend bool operator<(const Dollars& d, const Rupees& r);
    friend bool operator>=(const Dollars& d, const Rupees& r);
    friend bool operator<=(const Dollars& d, const Rupees& r);
    friend bool operator==(const Dollars& d, const Rupees& r);
    friend bool operator!=(const Dollars& d, const Rupees& r);
};

class Dollars {
    float amount;

public:
    // Constructor
    Dollars(float amt) : amount(amt) {}

    // Method to display amount
    void show() {
        cout << fixed << setprecision(2) << amount << " USD";
    }

    // Friend function declarations for operator overloading
    friend bool operator>(const Rupees& r, const Dollars& d);
    friend bool operator<(const Rupees& r, const Dollars& d);
    friend bool operator>=(const Rupees& r, const Dollars& d);
    friend bool operator<=(const Rupees& r, const Dollars& d);
    friend bool operator==(const Rupees& r, const Dollars& d);
    friend bool operator!=(const Rupees& r, const Dollars& d);

    friend bool operator>(const Dollars& d, const Rupees& r);
    friend bool operator<(const Dollars& d, const Rupees& r);
    friend bool operator>=(const Dollars& d, const Rupees& r);
    friend bool operator<=(const Dollars& d, const Rupees& r);
    friend bool operator==(const Dollars& d, const Rupees& r);
    friend bool operator!=(const Dollars& d, const Rupees& r);
};



// Overloaded operators for Rupees to Dollars comparison
bool operator>(const Rupees& r, const Dollars& d) {
    return r.amount > d.amount * 101.36;
}

bool operator<(const Rupees& r, const Dollars& d) {
    return r.amount < d.amount * 101.36;
}

bool operator>=(const Rupees& r, const Dollars& d) {
    return r.amount >= d.amount * 101.36;
}

bool operator<=(const Rupees& r, const Dollars& d) {
    return r.amount <= d.amount * 101.36;
}

bool operator==(const Rupees& r, const Dollars& d) {
    return r.amount == d.amount * 101.36;
}

bool operator!=(const Rupees& r, const Dollars& d) {
    return r.amount != d.amount * 101.36;
}

// Overloaded operators for Dollars to Rupees comparison
bool operator>(const Dollars& d, const Rupees& r) {
    return d.amount * 101.36 > r.amount;
}

bool operator<(const Dollars& d, const Rupees& r) {
    return d.amount * 101.36 < r.amount;
}

bool operator>=(const Dollars& d, const Rupees& r) {
    return d.amount * 101.36 >= r.amount;
}

bool operator<=(const Dollars& d, const Rupees& r) {
    return d.amount * 101.36 <= r.amount;
}

bool operator==(const Dollars& d, const Rupees& r) {
    return d.amount * 101.36 == r.amount;
}

bool operator!=(const Dollars& d, const Rupees& r) {
    return d.amount * 101.36 != r.amount;
}

int main() {
    float r, d;
    cout << "Enter amount in Rupees: ";
    cin >> r;
    cout << "Enter amount in Dollars: ";
    cin >> d;

    Rupees r1(r);
    Dollars d1(d);

    cout << "Comparisons between Rupees and Dollars:" << endl;
    cout << "Rupees > Dollars: " << (r1 > d1) << endl;
    cout << "Rupees < Dollars: " << (r1 < d1) << endl;
    cout << "Rupees >= Dollars: " << (r1 >= d1) << endl;
    cout << "Rupees <= Dollars: " << (r1 <= d1) << endl;
    cout << "Rupees == Dollars: " << (r1 == d1) << endl;
    cout << "Rupees != Dollars: " << (r1 != d1) << endl;

    cout << "Dollars > Rupees: " << (d1 > r1) << endl;
    cout << "Dollars < Rupees: " << (d1 < r1) << endl;
    cout << "Dollars >= Rupees: " << (d1 >= r1) << endl;
    cout << "Dollars <= Rupees: " << (d1 <= r1) << endl;
    cout << "Dollars == Rupees: " << (d1 == r1) << endl;
    cout << "Dollars != Rupees: " << (d1 != r1) << endl;

    return 0;
}
