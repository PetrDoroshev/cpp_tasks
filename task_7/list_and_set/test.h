#include <iostream>

class Test{

public:

    int Val;

    Test() {
        Val = 0;
        std::cout << "Constructor started" << std::endl;
    }

    ~Test(){
        std::cout << "Destructor started" << std::endl;
    }

    bool operator < (const Test& a){
        return Val < a.Val;
    }
    
    bool operator == (const int& a){
        return Val == a;
    }
    
};