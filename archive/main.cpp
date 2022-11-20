#include <iostream>
#include <fstream>
#include "archiver.h"


int main(int argc, char* argv[]) {

    Archiver a(128);

    std::ifstream input("./engwiki_ascii.txt");
    std::ofstream output;

    if (input.is_open()){
        a.compress(input, output);
    }
    else {
        std::cout << "Unable to open this file !" << std::endl;
    }


    return 0;
}