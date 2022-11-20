#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <unordered_map>

struct nearest
{
    int value;
    int index;
};
    

class Archiver{

private:
    
    std::vector<int> fibs;
    std::vector<std::string> code_words;

    std::vector<int> get_fibs(int max);
    std::string get_code(int n); 
    std::vector<std::string> get_codes(int n);
    nearest get_nearest(int n);

public:

    Archiver(int alphabet_size);

    void compress(std::ifstream& input, std::ofstream& output) const;
    void decompress(std::ifstream& input, std::ofstream& output) const;

};
