#include <iostream>
#include "Matrix.h"


int main() {

   Matrix<double> mac1(2, 3);

        Matrix<double> mac2(2, 3), mac3(2, 3);
        Matrix<double> *p;
        p = &mac3;
        (*p).state();
        p->state();
        for (int i = 1; i <= 2; i++)
            for (int j = 1; j <= 3; j++) {
                double x;
                std::cin >> x;
                mac1(i, j);
            }
        for (int i = 1; i <= 2; i++)
            for (int j = 1; j <= 3; j++) {
                double x;
                std::cin >> x;
                mac2(i, j);
            }
        mac1.state();
//
//        //mac3 = mac1.add(mac2);
//        //mac3 = mac1+mac2;
//        //mac3.state();
//       // mac1.multiply(mac2, mac3);
//        std::cout << std::endl;
//        mac3.state();
//        std::cout << std::endl;
//        //mac3 = 2 * mac1;
//        mac3 = mac1 * mac2;
//        mac3 = 2 * mac3;
//        mac3.state();
//        std::cout << std::endl;
//       // mac3.state();
//        std::cout << std::endl;
//        mac3.~Matrix();

    return 0;
}
