#include <set>
#include <list>
#include <algorithm>
#include <iostream>
#include "test.h"


int main(){

    std::list<Test> lst = {Test(), Test()};
    lst.sort();

    //std::set<Test> s;
    //s.insert(Test());
    //s.insert(Test());

    //std::cout << s.size() << std::endl;
    
    std::remove(lst.begin(), lst.end(), 0);

    return 0;
}