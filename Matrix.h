//
// Created by Kacper Chojnowski on 14/04/2024.
//

#ifndef MATRIX_OPERATIONS_MATRIX_H
#define MATRIX_OPERATIONS_MATRIX_H
#include <iostream>

template<class X>
class Matrix {
public:
    Matrix(int wie, int kol);
    Matrix(const Matrix& org);
    ~Matrix();
    X& operator()(size_t i, size_t j);
    const X& operator()(size_t i, size_t j) const;
    Matrix<X> operator+(const Matrix& v) const;
    Matrix<X> operator-(const Matrix& v) const;
    Matrix<X>& operator=(const Matrix<X>& org);
    Matrix<X> operator*(const Matrix& mat) const;
    template <typename U>
    friend Matrix<U> operator*(const double x, const Matrix<U>& v);

    void state() const;
private:
    X **m;
    int w, k;
};

template<typename T>
Matrix<T>::Matrix(int wie, int kol) : w(wie), k(kol) {
    m = new T *[wie];
    for (int i = 0; i < wie; i++)
        m[i] = new T[kol];
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
T& Matrix<T>::operator()(size_t i, size_t j) {
    if (i < 1 || i > w || j < 1 || j > k)
        throw std::out_of_range("Index out of range");
    return m[i - 1][j - 1];
}

template<typename T>
const T& Matrix<T>::operator()( size_t i, size_t j) const {
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
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& org) {
    if (this == &org)
        return *this;

    for (int i = 0; i < w; i++)
        delete[] m[i];
    delete[] m;

    w = org.w;
    k = org.k;
    m = new T *[w];
    for (int i = 0; i < w; i++)
        m[i] = new T[k];
    for (int i = 0; i < w; i++)
        for (int j = 0; j < k; j++)
            m[i][j] = org.m[i][j];

    return *this;
}

template<typename T>
Matrix<T> Matrix<T>::operator*(const Matrix& mat) const {
    if (k != mat.w)
        throw std::invalid_argument("Matrices size do not match for multiplication");
    Matrix wyn(w, mat.k);
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < mat.k; j++) {
            wyn.m[i][j] = 0;
            for (int l = 0; l < k; l++) {
                wyn.m[i][j] += m[i][l] * mat.m[l][j];
            }
        }
    }
    return wyn;
}

template<typename T>
Matrix<T> operator*(const double x, const Matrix<T>& v) {
    Matrix<T> wyn(v.w, v.k);
    for (int i = 0; i < v.w; i++)
        for (int j = 0; j < v.k; j++)
            wyn.m[i][j] = x * v.m[i][j];
    return wyn;
}

template<typename T>
void Matrix<T>::state() const {
    std::cout << "[ " << w << " , " << k << " ]" << std::endl;
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < k; j++) {
            std::cout << m[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

#endif //MATRIX_OPERATIONS_MATRIX_H
