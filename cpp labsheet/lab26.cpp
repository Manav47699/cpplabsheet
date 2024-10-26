#include <iostream>
#include <cstring>

using namespace std;

#define MAX_SIZE 100 

class STRING {
    char text[MAX_SIZE]; 
    int length;

public:

   STRING (const char t[])
   {
    length = strlen(t);
    strcpy (text,t);
   }


   STRING () {};

   STRING operator+ (STRING s2)
   {
    STRING t;
    strcpy (t.text, text);
    strcat (t.text, s2.text);
    return t;

   }
   void operator= (STRING t){

    strcpy (text, t.text);
   }

   bool operator== (STRING &o){
    return (strcmp(text, o.text));

   }

   void display (){
    cout << text << endl;
   }
};

int main() {
    STRING str1("Manav");
    STRING str2("Acharya");
    STRING str3 = str1 + str2;
    STRING str4("ManavAcharya");

    if (str3 == str4) {
        cout << "yes it's working" << endl;
        str3.display();
    } else {
        cout << "Not working" << endl;
        str3.display();
        str4.display();
    }

    return 0;
}

/*
    // Parameterized constructor
    STRING(const char t[]) {
        strncpy(text, t, MAX_SIZE - 1); // Copy up to MAX_SIZE - 1 characters
        text[MAX_SIZE - 1] = '\0'; // Ensure null termination
        length = strlen(text);
    }

    // Default constructor
    STRING() : length(0) {
        text[0] = '\0'; // Initialize to empty string
    }

    // Copy constructor
    STRING(const STRING& s) {
        strncpy(text, s.text, MAX_SIZE - 1);
        text[MAX_SIZE - 1] = '\0';
        length = s.length;
    }

    // Assignment operator
    STRING& operator=(const STRING& s) {
        if (this == &s) return *this; // Handle self-assignment

        strncpy(text, s.text, MAX_SIZE - 1);
        text[MAX_SIZE - 1] = '\0';
        length = s.length;
        return *this;
    }

    // Overloaded + operator
    STRING operator+(const STRING& s2) const {
        STRING t;
        int combinedLength = length + s2.length;
        if (combinedLength >= MAX_SIZE) combinedLength = MAX_SIZE - 1;
        
        strncpy(t.text, text, MAX_SIZE - 1);
        strncat(t.text, s2.text, combinedLength - length);
        t.text[MAX_SIZE - 1] = '\0';
        t.length = strlen(t.text);
        return t;
    }

    // Overloaded == operator
    bool operator==(const STRING& o) const {
        return strcmp(text, o.text) == 0;
    }

    // Method to display the string
    void display() const {
        cout << text << endl;
    }*/


/*#include <iostream>
#include <cstring>

using namespace std;

class STRING {
private:
    static const int MAX_SIZE = 100;
    char str[MAX_SIZE];
    int length;

public:

    STRING() : length(0) {
        str[0] = '\0';
    }

    STRING(const char* s) {
        length = strlen(s);
        if (length >= MAX_SIZE) {
            length = MAX_SIZE - 1;
        }
        strncpy(str, s, length);
        str[length] = '\0';
    }

    STRING(const STRING& other) {
        length = other.length;
        strncpy(str, other.str, length);
        str[length] = '\0';
    }

    STRING& operator=(const STRING& other) {
        if (this == &other) {
            return *this;
        }
        length = other.length;
        strncpy(str, other.str, length);
        str[length] = '\0';
        return *this;
    }

    STRING operator+(const STRING& other) const {
        STRING result;
        result.length = length + other.length;
        if (result.length >= MAX_SIZE) {
            result.length = MAX_SIZE - 1;
        }
        strncpy(result.str, str, length);
        strncat(result.str, other.str, MAX_SIZE - length - 1);
        result.str[result.length] = '\0';
        return result;
    }

    bool operator==(const STRING& other) const {
        return strcmp(str, other.str) == 0;
    }

    void display() const {
        cout << str << endl;
    }
};

int main() {
    STRING s1("Hello, ");
    STRING s2("World!");
    STRING s3;

    s3 = s1 + s2;

    cout << "s1: ";
    s1.display();
    cout << "s2: ";
    s2.display();
    cout << "s1 + s2: ";
    s3.display();

    if (s1 == s2) {
        cout << "s1 is equal to s2" << endl;
    } else {
        cout << "s1 is not equal to s2" << endl;
    }

    return 0;
}
*/