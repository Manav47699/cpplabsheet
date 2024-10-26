/* A parking garage charges a $2.00 minimum fee to park for up to three 
hours. The garage charges an additional $0.50 per hour for each hour or 
part thereof in excess of three hours. People who park their cars for 
longer than 24 hours will pay $8.00 per day. Write a program that 
calculates and prints the parking charges. The inputs to your program 
are the date and time when a car enters the parking garage, and the date
 and time when the same car leaves the parking garage. Keep track of 
number of cars in the garage overloading ++ and -- operators.*/


#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;

class ParkingGarage {
private:
    static int carCount;
    tm entryTime;
    tm exitTime;

public:
    ParkingGarage(tm entry, tm exit) : entryTime(entry), exitTime(exit) {}

    double calculateFee() const {

        time_t entry = mktime(const_cast<tm*>(&entryTime));
        time_t exit = mktime(const_cast<tm*>(&exitTime));
        double hours = difftime(exit, entry) / 3600.0;
        int fullHours = static_cast<int>(hours);
        int extraHour = (hours > fullHours) ? 1 : 0;

        if (hours <= 3) {
            return 2.00;
        } else if (hours <= 24) {
            return 2.00 + 0.50 * (fullHours + extraHour - 3);
        } else {
            return 8.00 * ((fullHours + extraHour) / 24 + ((fullHours + extraHour) % 24 > 0 ? 1 : 0));
        }
    }

    ParkingGarage& operator++() {
        ++carCount;
        return *this;
    }

    ParkingGarage& operator--() {
        --carCount;
        return *this;
    }

    static int getCarCount() {
        return carCount;
    }
};

int ParkingGarage::carCount = 0;

int main() {
    tm entryTime = {0, 0, 9, 1, 0, 121}; // means 9:00 AM, Jan 1, 2021
    tm exitTime = {0, 30, 16, 1, 0, 121}; // means 4:30 PM, Jan 1, 2021

    ParkingGarage pg(entryTime, exitTime);
    ++pg; // for car entry

    double fee = pg.calculateFee();
    cout << "Parking Fee: $" << fee << endl;
    cout << "Number of cars in garage: " << ParkingGarage::getCarCount() << endl;

    --pg; // for car  exit
    cout << "Number of cars in garage after exit: " << ParkingGarage::getCarCount() << endl;

    return 0;
}
