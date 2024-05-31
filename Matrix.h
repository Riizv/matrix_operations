//
// Created by Kacper Chojnowski on 14/04/2024.
//

#ifndef MATRIX_OPERATIONS_MATRIX_H
#define MATRIX_OPERATIONS_MATRIX_H

class Matrix {
public:
    Matrix(int wie, int kol);
    Matrix(const Matrix& org);
    ~Matrix();
    bool set(int i, int j, double x);
    double get(int i, int j);
    Matrix add(const Matrix& mac, Matrix& res);
    Matrix operator+(const Matrix& v) const;
    Matrix operator-(const Matrix& v) const;
    Matrix& operator=(const Matrix v);
    void multiply(const Matrix& macm, Matrix& resm);
    friend Matrix operator*(const double x, const Matrix& v);

    void state();
private:
    double **m;
    int w, k;
};

#endif //MATRIX_OPERATIONS_MATRIX_H
