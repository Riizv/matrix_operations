//
// Created by Kacper Chojnowski on 14/04/2024.
//

#ifndef MATRIX_OPERATIONS_MATRIX_H
#define MATRIX_OPERATIONS_MATRIX_H
#include <iostream>

template<typename T>
class Matrix {
public:
    Matrix<T>(int wie, int kol);
    Matrix<T>(const Matrix<T>& org);
    ~Matrix();
    T& operator()(Matrix &m, size_t i, size_t j);
    Matrix<T> operator+(const Matrix& v) const;
    Matrix<T> operator-(const Matrix& v) const;
    Matrix<T>& operator=(const Matrix& org);
    Matrix<T> operator*(const Matrix& mat) const;
    friend Matrix operator*(const double x, const Matrix& v);

    void state() const;
private:
    double **m;
    int w, k;
};

template<typename T>
Matrix<T>::Matrix(int wie, int kol) : w(wie), k(kol) {
    m = new double *[wie];
    for (int i = 0; i < wie; i++)
        m[i] = new double[kol];
}

template<typename T>
Matrix<T>::~Matrix() {
    for (int i = 0; i < w; i++)
        delete[] m[i];
    delete[] m;
    m = 0;
    w = 0;
    const int *pc;
    pc = &w;
    int *p;
    p = const_cast<int *>(pc);
    *p = 0;
    *const_cast<int *>(&k) = 0;
}

template<typename T>
Matrix<T>::Matrix(const Matrix<T> &org) : w(org.w), k(org.k) {
    m = new double *[w];
    for (int i = 0; i < w; i++)
        m[i] = new double[k];
    for (int i = 0; i < w; i++)
        for (int j = 0; j < k; j++)
            m[i][j] = org.m[i][j];
}

template<typename T>
T& Matrix<T>::operator()(Matrix &m, size_t i, size_t j) {
    if (i < 1 || i > w || j < 1 || j > k)
        throw std::out_of_range("Index out of range");
    return m[i - 1][j - 1];
}

template<typename T>
Matrix<T> Matrix<T>::operator+(const Matrix &v) const {
    if (w != v.w || k != v.k)
       throw std::invalid_argument("Matrices `size not match");
    Matrix wyn(w, k);
    for (int i = 0; i < w; i++)
        for (int j = 0; j < k; j++)
            wyn.m[i][j] = m[i][j] + v.m[i][j];
    return wyn;
}

template<typename T>
Matrix<T> Matrix<T>::operator-(const Matrix &v) const {
    if (w != v.w || k != v.k)
        throw std::invalid_argument("Matrices `size not match");
    Matrix wyn(w, k);
    for (int i = 0; i < w; i++)
        for (int j = 0; j < k; j++)
            wyn.m[i][j] = m[i][j] - v.m[i][j];
    return wyn;
}

template<typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix& org) {
    for (int i = 0; i < w; i++)
        for (int j = 0; j < k; j++)
            m[i][j] = org.m[i][j];
    return *this;
}

template<typename T>
void Matrix<T>::state() const {
    std::cout << "[ " << w << " , " << k << " ] \n";
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < k; j++) {
            std::cout << m[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

#endif //MATRIX_OPERATIONS_MATRIX_H
