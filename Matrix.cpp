/* Matthew Coughlin 2019 */
#include <iostream>
#include "Matrix.h"
using namespace std;

/**
 * Instantiates a 1x1 Matrix.
 */
Matrix::Matrix()
{
    rows.resize(1);
    rows[0].resize(1);
}

/**
 * Instantiates a numberOfRows x numberOfColumns Matrix.
 * 
 * @param numberOfRows the number of rows in the matrix.
 * @param numberOfColumns the number of columns in the matrix.
 */
Matrix::Matrix(const size_t numberOfRows, const size_t numberOfColumns)
{
    rows.resize(numberOfRows);
    for (long i = 0; i < rows.size(); i++)
    {
        rows[i].resize(numberOfColumns);
    }
}

/**
 * Deconstructs the Matrix.
 */
Matrix::~Matrix()
{
}

/**
 * Adds two matrices together.
 * 
 * @param otherMatrix is a reference to the second Matrix in the equation.
 * @param answer is the Matrix which will contain the sum.
 */
void Matrix::add(const Matrix &otherMatrix, Matrix &answer)
{
    if (rows.size() != otherMatrix.rows.size() || rows[0].size() != otherMatrix.rows[0].size())
    {
        cout << "Error, the matrices must have the same dimensions!\n";
        return;
    }

    answer.rows.resize(rows.size());
    for (unsigned long i = 0; i < rows.size(); i++)
    {
        answer.rows[i].resize(rows[i].size());
        for (unsigned long j = 0; j < otherMatrix.rows[0].size(); j++)
        {
            answer.rows[i][j] = rows[i][j] + otherMatrix.rows[i][j];
        }
    }
}

/**
 * Multiplies two matrices together.
 * 
 * @param otherMatrix the second Matrix in the equation.
 * @param answer the Matrix which will hold the product.
 */
void Matrix::multiply(const Matrix &otherMatrix, Matrix &answer)
{
    if (rows[0].size() != otherMatrix.rows.size())
    {
        cout << "Error, the number of columns in the left matrix must equal the number of rows in the right matrix!\n";
        return;
    }

    answer.rows.resize(rows.size());
    for (unsigned long i = 0; i < rows.size(); i++)
    {
        answer.rows[i].resize(otherMatrix.rows[i].size());
        for (unsigned long j = 0; j < otherMatrix.rows[0].size(); j++)
        {
            double sum = 0;
            for (unsigned long n = 0; n < rows[0].size(); n++)
            {
                sum += rows[i][n] * otherMatrix.rows[n][j];
            }

            answer.rows[i][j] = sum;
        }
    }
}

/**
 * Multiplies a Matrix by the given scalar.
 * 
 * @param scalar the scalar by which to multiply the Matrix.
 * @param answer the Matrix which will hold the product.
 */
void Matrix::multiply(const double scalar, Matrix &answer)
{
    for (unsigned long i = 0; i < rows.size(); i++)
    {
        for (unsigned long j = 0; j < rows[i].size(); j++)
        {
            answer.rows[i][j] = scalar * rows[i][j];
        }
    }
}

/**
 * Subtracts one Matrix from another.
 * 
 * @param otherMatrix the Matrix to subtract.
 * @param answer the Matrix which will hold the difference.
 */
void Matrix::subtract(const Matrix &otherMatrix, Matrix &answer)
{
}

/**
 * Divides a Matrix by another Matrix.
 * 
 * @param otherMatrix the divisor.
 * @param answer the Matrix which will hold the quotient.
 */
void Matrix::divide(const Matrix &otherMatrix, Matrix &answer)
{
}

/**
 * Transposes a Matrix.
 * 
 * @param desitnationMatrix the Matrix which will become the transpose of the calling Matrix.
 */
void Matrix::transpose(Matrix &desitnationMatrix)
{
    desitnationMatrix.rows.resize(rows[0].size());
    for (unsigned long i = 0; i < rows[0].size(); i++)
    {
        desitnationMatrix.rows[i].resize(rows.size());
        for (unsigned long j = 0; j < rows.size(); j++)
        {
            desitnationMatrix.rows[i][j] = rows[j][i];
        }
    }
}

/**
 * Generates the Identity Matrix of the calling Matrix.
 * 
 * @param eye the Matrix which will become the Identity Matrix.
 */
void Matrix::generateIdentity(Matrix &eye)
{
    const unsigned long rowCount = (unsigned long)rows.size();
    if (rowCount != rows[0].size())
    {
        cout << "Error, cannot generate an identity matrix for a matrix with dimensions of " << rowCount << "x" << rows[0].size() << "\n";
        return;
    }

    eye.rows.resize(rowCount);

    for (unsigned long row = 0; row < rowCount; row++)
    {
        eye.rows[row].resize(rowCount);
        for (unsigned long column = 0; column < rowCount; column++)
        {
            eye.rows[row][column] = row == column ? 1 : 0;
        }
    }
}

/**
 * Prints the elements of the Matrix in a grid format.
 */
void Matrix::print()
{
    cout << "\n";
    for (long i = 0; i < rows.size(); i++)
    {
        for (long j = 0; j < rows[i].size(); j++)
        {
            cout << " " << rows[i][j];
        }
        cout << "\n";
    }
    cout << "\n";
}

/**
 * The main program.
 */
int main()
{
    Matrix A = Matrix();
    Matrix B = Matrix(3, 3);
    B.rows[0][2] = 1;
    B.rows[2][1] = 2;

    A.print();
    B.print();

    Matrix eye = Matrix();
    eye.print();
    B.generateIdentity(eye);
    eye.print();

    Matrix sum = Matrix(3, 3);
    B.add(eye, sum);
    sum.print();

    Matrix C = Matrix(3, 4);
    for (short i = 0; i < C.rows.size(); i++)
    {
        for (short j = 0; j < C.rows[i].size(); j++)
        {
            C.rows[i][j] = rand() % 100;
        }
    }

    C.print();

    Matrix product = Matrix();
    B.multiply(C, product);
    product.print();

    Matrix trans = Matrix();
    B.transpose(trans);
    trans.print();

    return 0;
}