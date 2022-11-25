#include "trie.h"
#include <iostream>
#include <string>
#include <chrono>
#include <unordered_map>
#include <fstream>
#include "boxinfo.h"
//#include <cctype> //isalpha

void trieDict(const std::string& text, std::string word){

    using namespace std;
    Trie trie;
    string str = "";
    for (const auto &ch : text) // кроме последнего слова
    {
        //if(isalpha(ch) || ch == '\'')
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || ch == '\'')
            str += ch;
        else if (str.size() > 0) {
            trie.insert(str);
            str = "";
        }
    }
    cout << "\ntrie size: " << trie.size() << endl;
    cout << word << ": " << trie.find(word) << endl;

}


void umap(const std::string &text, std::string word)
{
    using namespace std;
    unordered_map<std::string, size_t> dict;
    string str = "";
    for (const auto &ch : text) // кроме последнего слова
    {
        //if(isalpha(ch) || ch == '\'')
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || ch == '\'')
            str += ch;
        else if (str.size() > 0) {
            ++dict[str];
            str = "";
        }
    }
    cout << "\ndict size: " << dict.size() << endl;
    cout << word << ": " << dict[word] << endl;
}

int main()
{   
    using namespace std;
    
    string text;
    ifstream fin("engwiki_ascii.txt", ios::binary);
    if (!fin.is_open()) {
        cout << "not open!" << endl;
        return 0;
    }
    text.append((istreambuf_iterator<char>(fin)), istreambuf_iterator<char>());
    fin.close();

    string word = "wiki";
    
    size_t N = 5;
    vector<double> times(N);


    for (size_t i = 0; i < N; i++){
    
        auto time_one = chrono::steady_clock::now();
        umap(text, word);
        auto time_two = chrono::steady_clock::now();
        times[i] = chrono::duration_cast<chrono::microseconds>(time_two - time_one).count() / 1e6;
        cout << "time: " << times[i] << " sec" << endl;
    }
    //auto res = boxInfo(times, 2);
    //cout << "mean: " << std::get<0>(res) << ", " << "median: " << std::get<1>(res) << ", " << "stddev: " << std::get<2>(res) << std::endl;
    

    for (size_t i = 0; i < N; i++) {

        auto time_one = chrono::steady_clock::now();
        trieDict(text, word);
        auto time_two = chrono::steady_clock::now();
        times[i] = chrono::duration_cast<chrono::microseconds>(time_two - time_one).count() / 1e6;
        cout << "time: " << times[i] << " sec" << endl;
    }
    //res = boxInfo(times, 2);
    //cout << "mean: " << std::get<0>(res) << ", " << "median: " << std::get<1>(res) << ", " << "stddev: " << std::get<2>(res) << std::endl;
}