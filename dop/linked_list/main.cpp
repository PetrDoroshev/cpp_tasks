#include <iostream>
#include "linked_list.cpp"

int main(){

    List<char> list = {};

    for ( int i = 0; i < 5; i ++)
        list.push_back ( char ('a' + i ) ) ;

    return 0;
}