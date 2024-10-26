#include <iostream>


using namespace std;



class MATRIX {
private:
    int rows;
    int cols;
    int data[100][100]; // Fixed-size array to store matrix elements
    public:
    MATRIX (int a, int b)
    {
        rows = a;
        cols = b;
    }

    MATRIX () {};

    void get() {
        cout <<"Enter the value of matrix" << endl;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cin >> data [rows][cols];
            }
            
        }
        
    }
    void put()
    {
        cout << "The sum of the matrix is \n";
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << data [rows][cols];
                cout << endl;
            }
            
        }
        
    }

    MATRIX operator+ (MATRIX b)
    {
        MATRIX c(rows,cols);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                c.data[rows][cols] = data[rows][cols] + b.data[rows][cols];
                return c;
            }
            
        }
        

    }
};

    int main(int argc, char const *argv[])
    {
        int rows, cols;
        cout << "Enter the size of arry";
        cin >> rows >> cols;
        MATRIX a(rows, cols) , b(rows, cols), c;
        a.get();
        b.get();
        c=a+b;
        c.put();
        return 0;
       
    }
    
/*
public:
    MATRIX(int m, int n) : rows(m), cols(n) {                          // parameterized constructor with an initializer list is used to initialize member variables (rows and cols) of the MATRIX class when creating objects. 
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

/*
    MATRIX operator+(const MATRIX& other) const {
    MATRIX result(rows, cols);                               // Create a result matrix with the same dimensions

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result.data[i][j] = data[i][j] + other.data[i][j];       // Perform element-wise addition
        }
    }

    return result; // Return the resulting matrix
}

MATRIX operator+(const MATRIX& other) const {                        //Ch3ecking the dimensions
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
*/