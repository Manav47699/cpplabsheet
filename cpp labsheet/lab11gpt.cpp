#include <iostream>
using namespace std;

class Distance
{
private:
    int feet1;
    int inches1;
    int feet2, inches2;
    int sumfeet, suminches;

public:
    void input()
    {
        cout << "Enter the first distance in feet and inch resp." << '\n';
        cin >> feet1 >> inches1;
        cout << "Enter the second distance in feet and inch resp.";
        cin >> feet2 >> inches2;
    }

    void show_input()
    {
        cout << feet1 << '\n' << inches1 << '\n' << feet2 << '\n' << inches2 << '\n';
    }

    void add()
    {
        sumfeet = feet1 + feet2;
        suminches = inches1 + inches2;
        if (suminches >= 12)
        {
            sumfeet++;
            suminches -= 12;
        }
        cout << "The total distance is " << sumfeet << " feet and " << suminches << " inches\n";
    }
};

int main()
{
    Distance distance; // Create an instance of the Distance class

    distance.input(); // Call the input method to get user input
    distance.show_input(); // Show the input values
    distance.add(); // Perform addition and display the result

    return 0;
}