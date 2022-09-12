#include <iostream>

int main(int argc, char* argv[]){
    
    if (argc - 1 != 3) {
        throw std::logic_error("invalid expression");
    }

    try {
            
        int a = std::stoi(argv[1]);
        int b = std::stoi(argv[3]);

        if (argv[2][0] == '+'){
            std::cout << a + b << std::endl;
        }
        else if (argv[2][0] == '-'){
            std::cout << a - b << std::endl;
        }
        else if (argv[2][0] == '*'){
            std::cout << a * b << std::endl;
        }
        else if (argv[2][0] == '/'){

            if (b == 0){
                throw std::logic_error("division by zero");
            }
            std::cout << a / b << std::endl; 
        }
        else if (argv[2][0] == '%'){
            std::cout << a * b << std::endl;
        }
            
    }
    catch (std::invalid_argument) {

        throw std::logic_error("not a number");
    }
        
    return 0;
}