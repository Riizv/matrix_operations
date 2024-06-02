//
// Created by Kacper Chojnowski on 14/04/2024.
//

#ifndef MATRIX_OPERATIONS_MATRIX_H
#define MATRIX_OPERATIONS_MATRIX_H

template<typename T>
class Matrix {
public:
    Matrix(int wie, int kol);
    Matrix(const Matrix& org);
    ~Matrix();
    bool set(int i, int j, double x);
    double get(int i, int j);
    Matrix operator+(const Matrix& v) const;
    Matrix operator-(const Matrix& v) const;
    Matrix& operator=(const Matrix org);
    Matrix operator*(const Matrix& mat) const;
    friend Matrix operator*(const double x, const Matrix& v);

    template<typename Q>
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
T Matrix<T>::set(int i, int j, double x) {
    if (i < 1 || i > w || j < 1 || j > k)
        return false;
    m[i - 1][j - 1] = x;
    return true;
}

#endif //MATRIX_OPERATIONS_MATRIX_H
