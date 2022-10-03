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

class Aggrigate{

public:

    Test m_objTest;

    Aggrigate() { std::cout << "Construction object of Aggrigate" << std::endl; }
    ~Aggrigate() { std::cout << "Destroying object of Aggrigate" << std::endl; }



};

