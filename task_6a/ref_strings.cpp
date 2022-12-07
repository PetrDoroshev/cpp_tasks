#include <iostream>
#include "Str.h"

int main() {

    Str s("lcl");
    Str s1;
    Str s2;

    s1 = s;
    s2 = s;

    s.reverse();
    std::cout << s << std::endl;
    std::cout << s1 << std::endl;
    std::cout << s2 << std::endl;

    return 0;
}