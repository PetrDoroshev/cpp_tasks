#include "archiver.h"

Archiver::Archiver(int alphabet_size) {

    fibs = get_fibs(alphabet_size);

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

std::vector<std::pair<char, int>> Archiver::get_freq_table(std::ifstream& input){

    std::unordered_map<char, int> freq_table;

    char c;
    while (input.get(c)) {
       ++freq_table[c];     
    }
    
    auto comp = [](std::pair<char, int>& a, std::pair<char, int>& b) { return a.second > b.second; };

    std::vector<std::pair<char, int>> items(freq_table.begin(), freq_table.end());
    std::sort(items.begin(), items.end(), comp);

    return items;


}   

void Archiver::compress(std::ifstream& input, std::ofstream& output) {

    auto freq_table = get_freq_table(input);

    std::unordered_map<char, std::string> encode_map;
    std::vector<char> decode_vector;

    for (std::size_t i = 0; i < freq_table.size(); i++){
        encode_map[freq_table[i].first] = get_code(i + 1);
        decode_vector.push_back(freq_table[i].first);
    }
    freq_table.clear();

    for(auto &c: decode_vector){
        output.put(c);
    }
    output.put('\0');

    input.clear();
    input.seekg(0, std::ios::beg);

    int bit;
    char buffer = 0;
    int bit_count = 0;

    char c;
    while (input.get(c)){
        for (auto &b: encode_map[c]){
            bit = b - ASCII_ZERO;
            buffer = buffer << 1 | bit;
            bit_count++;

            if (bit_count == 8){
                output.put(buffer);
                buffer = 0;
                bit_count = 0;
            }
        }
    }
    while (bit_count != 8){
        buffer = buffer << 1;
        bit_count++;
    }  
    output.put(buffer);

}


void Archiver::decompress(std::ifstream& input, std::ofstream& output){
    
    std::vector<char> decode_vector;

    char c;

    input.get(c);
    while (c != '\0'){
        decode_vector.push_back(c);
        input.get(c);
    }
    
    int true_bits = 0;
    int code_pos = 0;
    int symbol_index = 0;

    while (input.get(c)) {

        std::bitset<8> byte((unsigned long) c);
        for (int i = 7; i >= 0; i--){
            
            true_bits = (true_bits & byte[i]) + byte[i];

            if (true_bits == 2) {
                output.put(decode_vector[symbol_index - 1]);
                symbol_index = 0;
                code_pos = 0;
                continue;
            }
            symbol_index += fibs[code_pos] * byte[i];
            code_pos++;
        }
    }   
}
