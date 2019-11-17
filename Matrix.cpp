/* Matthew Coughlin 2019 */
#include <iostream>
#include "Matrix.h"
using namespace std;

Matrix::Matrix()
{
    rows.resize(1);
    rows[0].resize(1);
}

Matrix::Matrix(const size_t numberOfRows, const size_t numberOfColumns)
{
    rows.resize(numberOfRows);
    for (long i = 0; i < rows.size(); i++)
    {
        rows[i].resize(numberOfColumns);
    }
}

Matrix::~Matrix()
{
}

void Matrix::add(Matrix &otherMatrix)
{
}

void Matrix::multiply(Matrix &otherMatrix)
{
}

void Matrix::subtract(Matrix &otherMatrix)
{
}

void Matrix::divide(Matrix &otherMatrix)
{
}

void Matrix::transpose(Matrix &desitnationMatrix)
{
}

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
    }

    for (unsigned long row = 0; row < rowCount; row++)
    {
        for (unsigned long column = 0; column < rowCount; column++)
        {
            eye.rows[row][column] = row == column ? 1 : 0;
        }
    }
}

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

int main()
{
    Matrix A = Matrix();
    Matrix B = Matrix(3, 3);
    B.rows[2][1] = 7;

    A.print();
    B.print();

    Matrix eye = Matrix();
    B.generateIdentity(eye);

    eye.print();

    return 0;
}