#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <algorithm>
#include <bitset>

#define ASCII_ZERO 48

struct nearest
{
    int value;
    int index;
};
    

class Archiver{

private:
    
    std::vector<int> fibs;

    std::vector<int> get_fibs(int max);
    std::string get_code(int n); 
    std::vector<std::pair<char, int>> get_freq_table(std::ifstream& input);
    nearest get_nearest(int n);

public:

    Archiver(int alphabet_size);

    void compress(std::ifstream& input, std::ofstream& output);
    void decompress(std::ifstream& input, std::ofstream& output);

};
