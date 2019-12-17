/* Matthew Coughlin 2019 */
#ifndef MATRIX_H
#define MATRIX_H

#include <vector>

class Matrix
{
public:
    std::vector<std::vector<double>> rows;
    Matrix();
    Matrix(const size_t numberOfRows, const size_t numberOfColumns);
    ~Matrix();
    void add(const Matrix &otherMatrix, Matrix &answer);
    void multiply(const Matrix &otherMatrix, Matrix &answer);
    void multiply(const double scalar, Matrix &answer);
    void subtract(const Matrix &otherMatrix, Matrix &answer);
    void divide(Matrix &otherMatrix, Matrix &answer);
    void transpose(Matrix &destinationMatrix);
    void generateIdentity(Matrix &eye);
    void print();
};

#endif