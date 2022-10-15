#include <iostream>
#include "Test.h"
#include "Aggrigate.h"
#include "AggrigateT.h"


void foo(Test t){
    std::cout << "foo is running" << std::endl;
}

//Test test_;

int main(){

    //AggrigateT<Test> at;

    AggrigateT<Child> at;


    //Test test;
    //foo(test);

    //Aggrigate a; 
    //std::cout << (a.m_objTest).a << std::endl;

    //Child c;
    //std::cout << c.a << std::endl;

    //Test *p = new Test;

    //Test *pa = new Test[5];

    //delete p;
    //delete[] pa;
    return 0;
}