//
 //Create a 'MATRIX' class of size m X n. Overload the ‘+’ operator to  
 //Add Two MATRIX objects. Write a main function to implement it.
#include <iostream>

using namespace std;

class MATRIX {
private:
    int rows;
    int cols;
    int** data;                                    //Dynamic memory allocation for 2D array

public:
    MATRIX(int m, int n) : rows(m), cols(n) {
        data = new int*[rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new int[cols];
        }
    }

    ~MATRIX() {
        for (int i = 0; i < rows; ++i) {
            delete[] data[i];
        }
        delete[] data;
    }

    void input() {
        cout << "Enter the elements of the matrix (" << rows << "x" << cols << "):" << endl;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cin >> data[i][j];
            }
        }
    }

    void display() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }
    MATRIX operator+(const MATRIX& other) const {
        if (rows != other.rows || cols != other.cols) {
            throw invalid_argument("Matrices must have the same dimensions to be added.");
        }

        MATRIX result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }
};

int main() {
    int m, n;

    cout << "Enter the number of rows and columns for the matrices: ";
    cin >> m >> n;

    MATRIX mat1(m, n);
    MATRIX mat2(m, n);

    cout << "Input matrix 1:" << endl;
    mat1.input();

    cout << "Input matrix 2:" << endl;
    mat2.input();

    try {
        MATRIX result = mat1 + mat2;
        cout << "Resultant matrix after addition:" << endl;
        result.display();
    } catch (const invalid_argument& e) {
        cout << e.what() << endl;
    }

    return 0;
}