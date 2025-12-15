#include <iostream>
#include <vector>

#define MAX_ROWS 30
#define MAX_COLS 30

using namespace std;

class Matrix
{
private:
    int arr[MAX_ROWS][MAX_COLS];
    int rows, cols;

public:
    Matrix(int rows, int cols) : rows(rows), cols(cols) {}

    void input()
    {
        cout << "ENTER " << rows * cols << " MATRIX ELEMENTS: " << endl;
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                cin >> arr[i][j];
    }

    void display()
    {
        for (int i = 0; i < rows; i++)
        {
            {
                for (int j = 0; j < cols; j++)
                    cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }

    Matrix add(const Matrix &other)
    {
        Matrix result(rows, cols);

        if (rows != other.rows || cols != other.cols)
        {
            cout << "MATRIX ADDITION NOT POSSIBLE::INVALID MATRIX DIMENSIONS";
            return result;
        }
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                result.arr[i][j] = this->arr[i][j] + other.arr[i][j];

        return result;
    }

    Matrix subtract(const Matrix &other)
    {
        Matrix result(rows, cols);

        if (rows != other.rows || cols != other.cols)
        {
            cout << "MATRIX ADDITION NOT POSSIBLE::INVALID MATRIX DIMENSIONS";
            return result;
        }
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                result.arr[i][j] = this->arr[i][j] - other.arr[i][j];

        return result;
    }

    Matrix product(const Matrix &other)
    {
        Matrix result(rows, other.cols);
        if (this->cols != other.rows)
        {
            cout << "ERROR: Matrix Multiplication not possible. Invalid Matrix Dimensions! " << endl;
            return result;
        }

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < other.cols; j++)
            {
                result.arr[i][j] = 0;
                for (int k = 0; k < cols; k++)
                {
                    result.arr[i][j] += this->arr[i][k] * other.arr[k][j];
                }
            }
        }
        return result;
    }
};

int main()
{
    int rows, cols;
    cout << "ENTER DIMENSIONS OF MATRIX(m n): ";
    cin >> rows >> cols;

    Matrix A(rows, cols);

    cout << "\nMATRIX A" << endl;
    A.input();

    Matrix B(rows, cols);
    cout << "\nMATRIX B" << endl;
    B.input();

    Matrix sum = A.add(B);
    cout << "\n-------------------------------------------------------" << endl;
    cout << "SUM: " << endl;
    sum.display();

    cout << "\n-------------------------------------------------------" << endl;
    Matrix product = A.product(B);
    cout << "Product: " << endl;
    product.display();
    cout << "\n-------------------------------------------------------" << endl;
    return 0;
}
