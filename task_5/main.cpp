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

    //Child c;

    //Test *p = new Test;

    //Test *pa = new Test[5];

    //delete p;
    //delete[] pa;
    return 0;
}