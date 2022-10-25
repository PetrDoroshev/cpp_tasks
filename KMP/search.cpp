#include <iostream>
#include <string>
#include <chrono>
#include <unordered_map>
#include <fstream>
#include <vector>

using namespace std;

size_t search_naive(const string& T, const string& t){

    size_t index = string::npos;

    int k;
    int n = T.length();
    int m = t.length();

    for (int i = 0; i < n - m + 1; i++) {
        for (k = 0; k < m; k++) {
            if (t[k] != T[i + k]){
                break;
            }
        }
        if (k == m) {
            index = i;
            break;
        }
    }
    return index;
}

vector<size_t> prefix(const string& s){

    size_t n = s.length();
    vector <size_t> len(n);

    for (size_t i = 1; i < n; i++){
        
        size_t j = len[i - 1];

        while (j > 0 && s[i] != s[j])
           j = len[j - 1];

        if (s[i] == s[j])
            j++;
        
        len[i] = j;
    }
    return len;
}

size_t KMP(const string& T, const string& t){

    
    size_t index = string::npos;
    size_t Tn = T.length();
    size_t tn = t.length();
    vector<size_t> f = prefix(t);

    size_t j = 0; 
    for (size_t i = 0; i < Tn; i++) 
    {
        while ((j > 0) && (T[i] != t[j])) 
            j = f[j - 1];    
        if (T[i] == t[j]) 
            ++j;              
        if (j == tn) {
            index = i - tn + 1;
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

    string word = "was born in a small town called Sceptre"; 

    size_t N = 10;
    vector<double> times(N);
    vector<size_t> indx(N);

    cout << "Naive: " << endl;
    for (size_t i = 0; i < times.size(); i++){

        auto time_one = chrono::steady_clock::now();
        indx[i] = search_naive(text, word);
        auto time_two = chrono::steady_clock::now();

        times[i] = chrono::duration_cast<chrono::microseconds>(time_two - time_one).count();

    }


    for (size_t i = 0; i < times.size(); i++){
        cout << times[i] << '\t' << indx[i] << '\n';
    }
    

    cout << endl;
    cout << "KMP: " << endl;

    for (size_t i = 0; i < times.size(); i++){

        auto time_one = chrono::steady_clock::now();
        indx[i] = KMP(text, word);
        auto time_two = chrono::steady_clock::now();

        times[i] = chrono::duration_cast<chrono::microseconds>(time_two - time_one).count();

    }

    
    for (size_t i = 0; i < times.size(); i++){
        cout << times[i] << '\t' << indx[i] << '\n';
    }

    cout << endl;
    cout << "find: " << endl;

    for (size_t i = 0; i < times.size(); i++){

        auto time_one = chrono::steady_clock::now();
        indx[i] = text.find(word);
        auto time_two = chrono::steady_clock::now();

        times[i] = chrono::duration_cast<chrono::microseconds>(time_two - time_one).count();

    }
    
    for (size_t i = 0; i < times.size(); i++){
        cout << times[i] << '\t' << indx[i] << '\n';
    }
    

    return 0;

}

