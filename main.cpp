#include <iostream>
#include "Matrix.h"


int main() {
    {
        Matrix mac2(2, 3);
        mac2.set(1, 1, 5);
    }
    Matrix mac1(2, 3);
    {
        Matrix mac2(2, 3), mac3(2, 3);
        Matrix *p;
        p = &mac3;
        (*p).state();
        p->state();
        for (int i = 1; i <= 2; i++)
            for (int j = 1; j <= 3; j++) {
                double x;
                std::cin >> x;
                mac1.set(i, j, x);
            }
        for (int i = 1; i <= 2; i++)
            for (int j = 1; j <= 3; j++) {
                double x;
                std::cin >> x;
                mac2.set(i, j, x);
            }
        mac1.state();
        mac2.state();
        //mac3 = mac1.add(mac2);
        //mac1+mac2;
        //mac3.state();
       // mac1.multiply(mac2, mac3);
        std::cout << std::endl;
        mac1.state();
        std::cout << std::endl;
       // mac3.state();
        std::cout << std::endl;
        mac3.~Matrix();


    }
    mac1.state();
}
