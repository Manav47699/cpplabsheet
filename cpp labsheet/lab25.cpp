/*
#include<iostream>
#include<cstring>

using namespace std;

class STRING{
    char* text;            //char* is used for dynamic memory allocation
    int length;

    public:
        STRING(char t[]){
            length = strlen(t);
            text = new char[length + 1];      //syntax for creating a array of any size entered by the user
            strcpy(text, t);
        }

        STRING(){};

        ~STRING(){
            delete[] text;                 //Deallocates the dynamically allocated memory (text) to prevent memory leaks.
        }

        STRING operator+(STRING s2){
            STRING t;
            t.text = new char[length + s2.length + 1];
            strcpy(t.text, text);
            strcat(t.text, s2.text);
            return t;
        }

        void operator=(STRING t){
            text = new char[strlen(t.text)+1];
            strcpy(text, t.text);
        }

        bool operator == (STRING &o){
            return(!strcmp(text, o.text));
        }

        void display(){
            cout << text << endl;
        }
};

int main(){
    STRING str1("hello");
    STRING str2("world");
    STRING str3 = str1 + str2;
    STRING str4("helloworld");

    if(str3 == str4){
        cout << "yes it's working" << endl;
        str3.display();
    } else {
        cout << "Not working" << endl;
        str3.display();
        str4.display();
    }

    return 0;
}
*/
#include <iostream>
#include <cstring>

using namespace std;

class STRING {
    char* text;
    int length;

public:
    // Parameterized constructor
    STRING(const char t[]) {
        length = strlen(t);
        text = new char[length + 1];
        strcpy(text, t);
    }

    // Default constructor
    STRING() : text(new char[1]{'\0'}), length(0) {}

    // Copy constructor
    STRING(const STRING& s) {
        length = s.length;
        text = new char[length + 1];
        strcpy(text, s.text);
    }

    // Assignment operator
    STRING& operator=(const STRING& s) {
        if (this == &s) return *this; // Handle self-assignment

        delete[] text; // Deallocate old memory

        length = s.length;
        text = new char[length + 1];
        strcpy(text, s.text);
        return *this;
    }

    // Destructor
    ~STRING() {
        delete[] text;
    }

    // Overloaded + operator
    STRING operator+(const STRING& s2) const {
        STRING t;
        t.length = length + s2.length;
        t.text = new char[t.length + 1];
        strcpy(t.text, text);
        strcat(t.text, s2.text);
        return t;
    }

    // Overloaded == operator
    bool operator==(const STRING& o) const {
        return strcmp(text, o.text) == 0;
    }

    // Method to display the string
    void display() const {
        cout << text << endl;
    }
};

int main() {
    STRING str1("Manav");
    STRING str2("Acharya");
    STRING str3 = str1 + str2;
    STRING str4("ManavAcharya");

    if (str3 == str4) {
        cout << "code works" << endl;
        str3.display();
    } else {
        cout << "code does not work" << endl;
        str3.display();
        str4.display();
    }

    return 0;
}
