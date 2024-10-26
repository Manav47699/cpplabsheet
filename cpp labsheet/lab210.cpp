#include <iostream>
#include <stdexcept>

using namespace std;

class MATRIX {
private:
    int rows;
    int cols;
    int** data;

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

    friend MATRIX operator+(const MATRIX& mat1, const MATRIX& mat2) {
        if (mat1.rows != mat2.rows || mat1.cols != mat2.cols) {
            throw invalid_argument("Matrices must have the same dimensions to be added.");
        }

        MATRIX result(mat1.rows, mat1.cols);
        for (int i = 0; i < mat1.rows; ++i) {
            for (int j = 0; j < mat1.cols; ++j) {
                result.data[i][j] = mat1.data[i][j] + mat2.data[i][j];
            }
        }
        return result;
    }

    friend ostream& operator<<(ostream& output, const MATRIX& mat) {
        for (int i = 0; i < mat.rows; ++i) {
            for (int j = 0; j < mat.cols; ++j) {
                output << mat.data[i][j] << " ";
            }
            output << endl;
        }
        return output;
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
        cout << result;
    } catch (const invalid_argument& e) {
        cout << e.what() << endl;
    }

    return 0;
}