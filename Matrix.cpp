//
// Created by Kacper Chojnowski on 14/04/2024.
//

#include "Matrix.h"

//template<typename T>
//Matrix<T>::Matrix(int wie, int kol) : w(wie), k(kol) {
//    m = new double *[wie];
//    for (int i = 0; i < wie; i++)
//        m[i] = new double[kol];
//}

//
//Matrix::Matrix(const Matrix &org) : w(org.w), k(org.k) {
//    m = new double *[w];
//    for (int i = 0; i < w; i++)
//        m[i] = new double[k];
//    for (int i = 0; i < w; i++)
//        for (int j = 0; j < k; j++)
//            m[i][j] = org.m[i][j];
//}
//
//template<typename T>
//Matrix<T>::~Matrix() {
//    for (int i = 0; i < w; i++)
//        delete[] m[i];
//    delete[] m;
//    m = 0;
//    w = 0;
//    const int *pc;
//    pc = &w;
//    int *p;
//    p = const_cast<int *>(pc);
//    *p = 0;
//    *const_cast<int *>(&k) = 0;
//}
//
//bool Matrix::set(int i, int j, double x) {
//    if (i < 1 || i > w || j < 1 || j > k)
//        return false;
//    m[i - 1][j - 1] = x;
//    return true;
//}
//
//#include <iostream>
//
//double Matrix::get(int i, int j) {
//    if (i < 1 || i > w || j < 1 || j > k) {
//        std::cout << "Matrix get - index(s) out of range ";
//        exit(7);
//    }
//    return m[i - 1][j - 1];
//}
//
//Matrix Matrix::operator+(const Matrix &v) const {
//    Matrix wyn(w, k);
//    for (int i = 0; i < w; i++)
//        for (int j = 0; j < k; j++)
//            wyn.m[i][j] = m[i][j] + v.m[i][j];
//    return wyn;
//}
//
//Matrix Matrix::operator-(const Matrix &v) const {
//    Matrix wyn(w, k);
//    for (int i = 0; i < w; i++)
//        for (int j = 0; j < k; j++)
//            wyn.m[i][j] = m[i][j] - v.m[i][j];
//    return wyn;
//}
//
//Matrix operator*(const double x, const Matrix &v) {
//    Matrix res(v.w, v.k);
//    for (int i = 0; i < v.w; i++)
//        for (int j = 0; j < v.k; j++)
//            res.m[i][j] = x * v.m[i][j];
//    return res;
//}
//
//Matrix &Matrix::operator=(const Matrix org) {
//    for (int i = 0; i < w; i++)
//        for (int j = 0; j < k; j++)
//            m[i][j] = org.m[i][j];
//    return *this;
//}
//
//Matrix Matrix::operator*(const Matrix &mat) const {
//    if (w != mat.w || k != mat.k)
//        throw std::invalid_argument("Matrix multiply - size not match");
//
//    Matrix res(w, mat.k);
//    for (int i = 0; i < w; i++)
//        for (int j = 0; j < k; j++)
//            res.m[i][j] += m[i][j] = m[i][j] * mat.m[i][j];
//    return res;
//}
//
//template<typename T>
//void Matrix<T>::state() {
//    std::cout << "[ " << w << " , " << k << " ] \n";
//    for (int i = 0; i < w; i++) {
//        for (int j = 0; j < k; j++) {
//            std::cout << m[i][j] << "\t";
//        }
//        std::cout << std::endl;
//    }
//}