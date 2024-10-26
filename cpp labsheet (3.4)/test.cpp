#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class Book {
    char author[30];
    int price;
public:
    void setdata() {
        cout << "Enter author name: ";
        cin.ignore(); // Clear the input buffer
        cin.getline(author, sizeof(author)); // Read full author name
        cout << "Enter price: ";
        cin >> price; 
    }

    void display() {
        cout << "Author: " << author << ", Price: " << price << endl;
    }

    int getPrice() {
        return price;
    }

    char* getAuthor() {
        return author;
    }
};

void addrecord() {
    fstream fin;
    fin.open("book.txt", ios::app | ios::out | ios::binary); // Ensure correct file extension
    Book b;
    b.setdata();
    fin.write((char*)&b, sizeof(b));
    fin.close();
}

void displayrecord() {
    fstream fout;
    Book b;
    fout.open("book.txt", ios::in | ios::binary);
    while (fout.read((char*)&b, sizeof(b))) {
        b.display();
    }
    fout.close();
}

void searchByPrice(int targetPrice) {
    fstream fout;
    Book b;
    fout.open("book.txt", ios::in | ios::binary);
    bool found = false;
    while (fout.read((char*)&b, sizeof(b))) {
        if (b.getPrice() == targetPrice) {
            cout << "Author found: " << b.getAuthor() << " at price: " << targetPrice << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No author found with the price: " << targetPrice << endl;
    }
    fout.close();
}

int main() {
    int n;
    cout << "Enter 1 to add data, 2 to view data, or 3 to search by price: " << endl;
    cin >> n;
    switch (n) {
    case 1:
        addrecord();
        break;
    case 2:
        displayrecord();
        break;
    case 3: {
        int priceToSearch;
        cout << "Enter price to search: ";
        cin >> priceToSearch;
        searchByPrice(priceToSearch);
        break;
    }
    default: 
        cout << "Enter a valid option" << endl;
        break;
    }
    return 0;
}
