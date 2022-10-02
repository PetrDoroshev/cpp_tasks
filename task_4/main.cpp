#include "Str.h"
#include <iostream>


void test(Str s){

}

int main(){

    Str s = "a";
    std::cout << s << std::endl;

    Str t;
    t = s;
    std::cout << s << std::endl;
    t = "c";

    s += "b";
    std::cout << s << std::endl;

    std::cout << s + t << std::endl;


    return 0;
}