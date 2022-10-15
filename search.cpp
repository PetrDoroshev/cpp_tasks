#include <iostream>
#include <string>
#include <chrono>
#include <unordered_map>
#include <fstream>
#include <vector>

using namespace std;

size_t search_naive(const string& T, const string& t){

    size_t index = string::npos;
    int n = T.length();
    int m = t.length();

    for (int i = 0; i < n - m + 1; i++){
        for (int k = 0; k < m; k++) {

            if (t[k] != T[i + k]){
                index = string::npos;
                break;
            }
            index = i;
        }
        if (index != string::npos){
            break;
        }
    }
    return index;
}

int main(){

    string text;
    ifstream fin("engwiki_ascii.txt", ios::binary);
    if (!fin.is_open())
    {
        cout << "not open!" << endl;
        return 0;
    }
    text.append((istreambuf_iterator<char>(fin)), istreambuf_iterator<char>());

    string word = "wiki"; 

    size_t N = 10;
    vector<size_t> times(N);
    vector<size_t> indx(N);


    for (size_t i = 0; i < times.size(); i++){

        auto time_one = chrono::steady_clock::now();
        indx[i] = search_naive(text, word);
        auto time_two = chrono::steady_clock::now();

        times[i] = chrono::duration_cast<chrono::microseconds>(time_two - time_one).count();

    }

    for (size_t i = 0; i < times.size(); i++){
        cout << times[i] << '\t' << indx[i] << '\n';
    }

    return 0;

}

