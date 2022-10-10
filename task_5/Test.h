#include <iostream>

class Test{

public:

    static int n_count;
    int a;

    Test();
    Test(const Test& t);
    Test(int a);
    ~Test();


};

class Child: public Test {

public:

    Child();
    ~Child();

};


