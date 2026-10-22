#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <chrono>
#include "archiver.h"

int get_file_size(std::ifstream& file){
    std::streampos begin, end;
    
    file.clear();
    file.seekg(0, std::ios::beg);
    begin = file.tellg();

    file.seekg (0, std::ios::end);
    end = file.tellg();

    return (end - begin);
}


int get_file_size(std::ofstream& file){
    std::streampos begin, end;
    
    file.clear();
    file.seekp(0, std::ios::beg);
    begin = file.tellp();

    file.seekp (0, std::ios::end);
    end = file.tellp();

    return (end - begin);

}

int main(int argc, char* argv[]) {

    Archiver archiver(128);
    std::ifstream input;
    std::ofstream output;

    if (argc != 4){
        throw std::logic_error("Number of arguments must be 3");
    }
    
    if (std::string{argv[1]} == "-c"){

        std::ifstream input(argv[2]);
        std::ofstream output(argv[3], std::ios::binary);

        if (input.is_open() && output.is_open()){
            
            auto time_one = std::chrono::steady_clock::now();
            archiver.compress(input, output);
            auto time_two = std::chrono::steady_clock::now();

            double time = std::chrono::duration_cast<std::chrono::microseconds>(time_two - time_one).count() / 1e6;

            int input_size = get_file_size(input);
            int output_size = get_file_size(output);
            double ratio = (double)input_size / (double)output_size;

            std::cout << "Compression done in " << time << " sec" << std::endl;
            printf("Compression ratio: %d bytes / %d bytes = %lf\n", input_size, output_size, ratio);

            input.close();
            output.close();

        }
        else {
            std::cout << "Unable to open this file!" << std::endl;
        }
    }
    else if (std::string{argv[1]} == "-d"){

        std::ifstream input(argv[2], std::ios::binary);
        std::ofstream output(argv[3]);

        if (input.is_open() && output.is_open()){

            auto time_one = std::chrono::steady_clock::now();
            archiver.decompress(input, output);
            auto time_two = std::chrono::steady_clock::now();
    

            double time = std::chrono::duration_cast<std::chrono::microseconds>(time_two - time_one).count() / 1e6;

            std::cout << "Decompression done in " << time << " sec" << std::endl;

            input.close();
            output.close();
        }

    }
    else {
        std::cout << "Unknown flag! Alowable flags: -h, -c, -d" << std::endl;
    }

    return 0;
}