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
    void add(Matrix &otherMatrix);
    void multiply(Matrix &otherMatrix);
    void subtract(Matrix &otherMatrix);
    void divide(Matrix &otherMatrix);
    void transpose(Matrix &destinationMatrix);
    void generateIdentity(Matrix &eye);
    void print();
};

#endif