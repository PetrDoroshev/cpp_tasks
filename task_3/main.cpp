#include "complex.h"
#include <iostream>


int main(){

    Complex c1;
    Complex c2(3, 1);

    std::cout << c1 << std::endl;
    std::cout << c1 + c2 << std::endl;
    std::cout << c1 - c2 << std::endl;
    std::cout << c1 * c2 << std::endl;
    std::cout << c1 / c2 << std::endl;
    std::cout << c1.conjugate() << std::endl;
    std::cout << c1.arg() << std::endl;

    Complex v[4] { 1, 2, Complex (2,3), 5 };

    for (int i = 0; i < 4; i++){
        std::cout << v[i] << ' ';
    }
    std::cout << std::endl;

    Complex *pc;

    pc = new Complex(1, 2);
    std::cout << *pc << std::endl;
    std::cout << pc->Re << std::endl;
    std::cout << pc->Im << std::endl;

    Complex* complex_array = new Complex[5];
    std::cout << complex_array[1] << std::endl;

    delete pc;
    delete[] complex_array;
    
    return 0;
}