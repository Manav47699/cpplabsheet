#include <iostream>
#include <stdexcept>

using namespace std;

class MATRIX {
private:
    int rows;
    int cols;
    int data[100][100]; // Fixed-size array to store matrix elements

public:
    MATRIX(int m, int n) : rows(m), cols(n) {
        // Initialize matrix with zeros
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                data[i][j] = 0;
            }
        }
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

    bool canAdd(const MATRIX& other) const {
        return (rows == other.rows && cols == other.cols);
    }

    MATRIX operator+(const MATRIX& other) const {
        if (!canAdd(other)) {                                                                                  // Optionally handle the error condition here
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

    if (mat1.canAdd(mat2)) {
        MATRIX result = mat1 + mat2;
        cout << "Resultant matrix after addition:" << endl;
        result.display();
    } else {
        cout << "Matrices must have the same dimensions to be added." << endl;
    }

    return 0;
}
