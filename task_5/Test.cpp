#include "Test.h"

int Test::n_count = 0;

Test::Test(){
    n_count += 1;
    std::cout << "Constructing object of Test, " <<  "n_count = " << n_count << std::endl; 
}

Test::~Test(){
    n_count -= 1;
    std::cout << "Destroying object of Test, " << "n_count = " << n_count << std::endl;
}

Test::Test(const Test& t){
    n_count += 1;
    std::cout << "Copying object of Test, " << "n_count = " << n_count << std::endl;
}

Child::Child(){
    n_count += 1;
    std::cout << "Constructing object of Child, " <<  "n_count = " << n_count << std::endl; 
}

Child::~Child(){
    n_count -= 1;
    std::cout << "Destroying object of Child, " << "n_count = " << n_count << std::endl;

}


