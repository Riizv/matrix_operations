#include <iostream>
#include "Matrix.h"

int main() {
    // Initialize matrices with compatible sizes for multiplication
    Matrix<double> mac1(2, 3);
    Matrix<double> mac2(3, 2);
    Matrix<double> mac3(2, 2);
    Matrix<double> *p;
    p = &mac3;
    std::cout << *p << std::endl;

    try {
        // Input elements for mac1 (2x3 matrix)
        std::cout << "Enter elements for mac1 (2x3 matrix):" << std::endl;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                double x;
                std::cin >> x;
                mac1(i, j) = x;
            }
        }

        // Input elements for mac2 (3x2 matrix)
        std::cout << "Enter elements for mac2 (3x2 matrix):" << std::endl;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 2; j++) {
                double x;
                std::cin >> x;
                mac2(i, j) = x;
            }
        }

        // Display mac1 state
        std::cout << "mac1 state:" << std::endl;
        std::cout << mac1 << std::endl;

        // Display mac2 state
        std::cout << "mac2 state:" << std::endl;
        std::cout << mac2 << std::endl;

        // Perform matrix multiplication and print the result
        mac3 = mac1 * mac2;
        std::cout << "mac3 after multiplication (mac1 * mac2):" << std::endl;
        std::cout << mac3 << std::endl;

        // Scalar multiplication
        Matrix<double> mac4 = 2 * mac1;
        std::cout << "mac4 after scalar multiplication (2 * mac1):" << std::endl;
        std::cout << mac4 << std::endl;

    } catch (const std::invalid_argument &e) {
        std::cerr << "Matrix error: " << e.what() << std::endl;
    }

    return 0;
}
