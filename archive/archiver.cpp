#include "archiver.h"

Archiver::Archiver(int alphabet_size) {

    fibs = get_fibs(alphabet_size);
    code_words = get_codes(alphabet_size);
}

std::vector<int> Archiver::get_fibs(int max){

    std::vector<int> _fibs;
    int n0 = 1;
    int n1 = 1;

    do {
        _fibs.push_back(n1);
        n1 = n0 + n1;
        n0 = n1 - n0;

    } while (n1 < max);

    return _fibs;
}

nearest Archiver::get_nearest(int n){

    int max_fib_index = fibs.size() - 1;

    if (n >= fibs[max_fib_index])
        return nearest {fibs[max_fib_index], max_fib_index};

    for (int i = 0; i < max_fib_index; i++) {

        if (fibs[i + 1] > n)
            return nearest {fibs[i], i};
    }
    
    return nearest{0, 0};

}

std::string Archiver::get_code(int n) {    
    
    auto _nearest = get_nearest(n);
    std::string code_word(_nearest.index, '0');
    code_word += "11";

    n -= _nearest.value;

    while (n != 0) {
        _nearest = get_nearest(n);
        code_word[_nearest.index] = '1';
        n -= _nearest.value; 
    }
    
    return code_word;
}

std::vector<std::string> Archiver::get_codes(int n){

    std::vector<std::string> _code_words;

    for (int i = 0; i < n; i++) {
        _code_words.push_back(get_code(i + 1));
    }
    return _code_words;
}

void Archiver::compress(std::ifstream& input, std::ofstream& output) const {

    std::unordered_map<char, int> freq_table;

    char c;
    while (input.get(c)) {
       ++freq_table[c];     
    }
}

