#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>

class Matrix {
    private:
        std::vector<std::vector<double>> data;
        int rows;
        int cols;

    public:
        Matrix(int rows, int cols);
        Matrix(const std::vector<std::vector<double>>& values);

        int getRows() const;
        int getCols() const;

        Matrix operator+(const Matrix& other) const;
        Matrix operator=(const Matrix& other) const;
        Matrix operator*(const Matrix& other) const;
        Matrix transpose() const;
        Matrix inverse() const;
        Matrix scalar(float scalar) const;
        Matrix trace() const;
        double determinant() const;

        bool isOrthogonal() const;
        bool isIdentity() const;
        bool isSquare(int rows, int cols) const;

        void display() const;
};

#endif