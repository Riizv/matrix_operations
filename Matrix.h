//
// Created by X on 14/04/2024.
//

#ifndef MATRIX_OPERATIONS_MATRIX_H
#define MATRIX_OPERATIONS_MATRIX_H

#include <iostream>
#include <stdexcept>  // Include for exception handling

// Template class for Matrix
template<class X>
class Matrix {
public:
    // Constructor to initialize matrix with given dimensions
    Matrix(int wie, int kol);

    // Copy constructor
    Matrix(const Matrix& org);

    // Destructor
    ~Matrix();

    // Operator() to access elements (non-const version)
    X& operator()(size_t i, size_t j);

    // Operator() to access elements (const version)
    const X& operator()(size_t i, size_t j) const;

    // Operator+ for matrix addition
    Matrix<X> operator+(const Matrix& v) const;

    // Operator- for matrix subtraction
    Matrix<X> operator-(const Matrix& v) const;

    // Assignment operator
    Matrix<X>& operator=(const Matrix<X>& org);

    // Operator* for matrix multiplication
    Matrix<X> operator*(const Matrix& mat) const;

    // Friend function for scalar multiplication
    template <typename U>
    friend Matrix<U> operator*(const double x, const Matrix<U>& v);

    // Friend function for output stream
    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const Matrix<U>& matrix);

private:
    X **m;  // Pointer to the 2D array (matrix elements)
    int w, k;  // Dimensions of the matrix (w: rows, k: columns)
};

// Constructor: Initialize matrix with given dimensions and zero out all elements
template<typename T>
Matrix<T>::Matrix(int wie, int kol) : w(wie), k(kol) {
    m = new T *[wie];
    for (int i = 0; i < wie; i++)
        m[i] = new T[kol]();  // Initialize with default values (zero for basic types)
}

// Destructor: Release allocated memory
template<typename T>
Matrix<T>::~Matrix() {
    for (int i = 0; i < w; i++)
        delete[] m[i];
    delete[] m;
}

// Copy constructor: Create a deep copy of the original matrix
template<typename T>
Matrix<T>::Matrix(const Matrix<T> &org) : w(org.w), k(org.k) {
    m = new T *[w];
    for (int i = 0; i < w; i++)
        m[i] = new T[k];
    for (int i = 0; i < w; i++)
        for (int j = 0; j < k; j++)
            m[i][j] = org.m[i][j];
}

// Operator(): Access element at (i, j) with bounds checking (non-const version)
template<typename T>
T& Matrix<T>::operator()(size_t i, size_t j) {
    if (i >= w || j >= k)
        throw std::out_of_range("Index out of range");
    return m[i][j];
}

// Operator(): Access element at (i, j) with bounds checking (const version)
template<typename T>
const T& Matrix<T>::operator()(size_t i, size_t j) const {
    if (i >= w || j >= k)
        throw std::out_of_range("Index out of range");
    return m[i][j];
}

// Operator+: Add two matrices
template<typename T>
Matrix<T> Matrix<T>::operator+(const Matrix &v) const {
    if (w != v.w || k != v.k)
        throw std::invalid_argument("Matrices size not match");
    Matrix wyn(w, k);
    for (int i = 0; i < w; i++)
        for (int j = 0; j < k; j++)
            wyn.m[i][j] = m[i][j] + v.m[i][j];
    return wyn;
}

// Operator-: Subtract two matrices
template<typename T>
Matrix<T> Matrix<T>::operator-(const Matrix &v) const {
    if (w != v.w || k != v.k)
        throw std::invalid_argument("Matrices size not match");
    Matrix wyn(w, k);
    for (int i = 0; i < w; i++)
        for (int j = 0; j < k; j++)
            wyn.m[i][j] = m[i][j] - v.m[i][j];
    return wyn;
}

// Assignment operator: Assign one matrix to another with deep copy
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

// Operator*: Multiply two matrices
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

// Friend function for scalar multiplication
template<typename T>
Matrix<T> operator*(const double x, const Matrix<T>& v) {
    if (v.m == nullptr)
        throw std::invalid_argument("Matrix is not initialized for scalar multiplication");

    Matrix<T> wyn(v.w, v.k);
    for (int i = 0; i < v.w; i++)
        for (int j = 0; j < v.k; j++)
            wyn.m[i][j] = x * v.m[i][j];
    return wyn;
}

// Friend function for output stream
template<typename T>
std::ostream& operator<<(std::ostream& os, const Matrix<T>& matrix) {
    os << "[ " << matrix.w << " , " << matrix.k << " ]" << std::endl;
    for (int i = 0; i < matrix.w; i++) {
        for (int j = 0; j < matrix.k; j++) {
            os << matrix.m[i][j] << "\t";
        }
        os << std::endl;
    }
    return os;
}

#endif //MATRIX_OPERATIONS_MATRIX_H

