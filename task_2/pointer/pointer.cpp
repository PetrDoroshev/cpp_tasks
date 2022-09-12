#include <iostream>

void swap(int* pa, int* pb);
void swap(int& a, int& b);

int main(){
    /*
    int x = 3;
    int *p = &x;
    std::cout << x << ' ' << *p << ' ' << p << std::endl;
    p++;
    std::cout << p - &x << std::endl;


    typedef unsigned char byte;

    byte *pb = (byte*)--p;
    for (byte *pt = pb; pt - pb < sizeof(int); pt++)
		std::cout << (int)*pt << ' ';
    std::cout << std::endl << std::endl;
    */

    int a = 3; int b = 5;
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;

    swap(a, b);

    std::cout << std::endl;
    std::cout << "after swap: " << std::endl;
    std::cout << std::endl;
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;



    return 0;
}

void swap(int* pa, int* pb){

    int tmp = *pa;
    *pa = *pb;
    *pb = tmp;
}

void swap(int& a, int& b){
    int tmp = a;
    a = b;
    b = tmp;
}
