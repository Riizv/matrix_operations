//
// Created by Kacper Chojnowski on 14/04/2024.
//

#include "Matrix.h"

Matrix::Matrix(int wie, int kol) : w(wie), k(kol) {
    m = new double *[wie];
    for (int i = 0; i < wie; i++)
        m[i] = new double[kol];
}

Matrix::Matrix(const Matrix &org) : w(org.w), k(org.k) {
    m = new double *[w];
    for (int i = 0; i < w; i++)
        m[i] = new double[k];
    for (int i = 0; i < w; i++)
        for (int j = 0; j < k; j++)
            m[i][j] = org.m[i][j];
}

Matrix::~Matrix() {
    for (int i = 0; i < w; i++)
        delete[] m[i];
    delete[] m;
    m = 0;
    //w = 0;
    const int *pc;
    pc = &w;
    int *p;
    p = const_cast<int *>(pc);
    *p = 0;
    *const_cast<int *>(&k) = 0;
}

bool Matrix::set(int i, int j, double x) {
    if (i < 1 || i > w || j < 1 || j > k)
        return false;
    m[i - 1][j - 1] = x;
    return true;
}

#include <iostream>

double Matrix::get(int i, int j) {
    if (i < 1 || i > w || j < 1 || j > k) {
        std::cout << "Matrix get - index(s) out of range ";
        exit(7);
    }
    return m[i - 1][j - 1];
}

//Matrix Matrix::add(const Matrix& mac){
//    if(w != mac.w || k != mac.k){
//        std::cout << "Matrix add - can not add two different dimension in matrix ";
//        exit(9);
//    }
//    Matrix wyn(w, k);
//    for(int i = 0; i < w; i++)
//        for(int j = 0; j < k; i++)
//            wyn.m[i][j] = m[i][j] + mac.m[i][j];
//
//}

void Matrix::add(const Matrix &mac, Matrix &res) {
    if (this->w != mac.w || k != mac.k) {
        std::cout << "Matrix add - size not match";
        exit(9);
    }
    //Macierz wyn(w, k);
    for (int i = 0; i < w; i++)
        for (int j = 0; j < k; j++)
            res.m[i][j] = m[i][j] + mac.m[i][j];
    //return wyn;
}

Matrix &Matrix::operator=(const Matrix org) {
    for (int i = 0; i < w; i++)
        for (int j = 0; j < k; j++)
            m[i][j] = org.m[i][j];
    return *this;
}

void Matrix::multiply(const Matrix &macm, Matrix &resm) {
    if (this->w != macm.w || k != macm.k) {
        std::cout << "Matrix multiply - size not match";
        exit(9);
    }
    //Macierz wyn(w, k);
    for (int i = 0; i < w; i++)
        for (int j = 0; j < k; j++)
            resm.m[i][j] = m[i][j] * macm.m[i][j];
    //return wyn;
}

void Matrix::state() {
    std::cout << "[ " << w << " , " << k << " ] \n";
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < k; j++) {
            std::cout << m[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}