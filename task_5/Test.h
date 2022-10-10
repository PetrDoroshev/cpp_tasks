#include <iostream>

class Test{

public:

    static int n_count;

    Test();
    Test(const Test& t);
    ~Test();


};

class Child: public Test {

public:

    Child();
    ~Child();

};


