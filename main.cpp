#include <iostream>
#include "Matrix.h"

int main() {
    Matrix<double> mac1(2, 3);
    Matrix<double> mac2(2, 3), mac3(2, 3);
    Matrix<double> *p;
    p = &mac3;
    (*p).state();
    p->state();

    std::cout << "Enter elements for mac1 (2x3 matrix):" << std::endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            double x;
            std::cin >> x;
            mac1(i, j) = x;
        }
    }

    std::cout << "Enter elements for mac2 (2x3 matrix):" << std::endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            double x;
            std::cin >> x;
            mac2(i, j) = x;
        }
    }

    std::cout << "mac1 state:" << std::endl;
    mac1.state();

    std::cout << "mac2 state:" << std::endl;
    mac2.state();

    // Perform matrix addition and print the result
    mac3 = mac1 + mac2;
    std::cout << "mac3 after addition (mac1 + mac2):" << std::endl;
    mac3.state();

    // Perform matrix multiplication and print the result
    try {
        mac3 = mac1 * mac2;
        std::cout << "mac3 after multiplication (mac1 * mac2):" << std::endl;
        mac3.state();
    } catch (const std::invalid_argument &e) {
        std::cerr << "Matrix multiplication error: " << e.what() << std::endl;
    }

    // Scalar multiplication
    mac3 = 2 * mac1;
    std::cout << "mac3 after scalar multiplication (2 * mac1):" << std::endl;
    mac3.state();

    return 0;
}
