#include <iostream>
#include <cstring>

void string_copy(char* d, char* s);
int len(const char* s);
int compare(const char* s, const char* t);

int main(){

    char str[] = "Hello";
    std::cout << str << std::endl;
    std::cout << strlen(str) << ' ' << sizeof(str) << std::endl;


    char t[32];
    string_copy(t, str);
    std::cout << t << std::endl;

    std::cout << len(t) << std::endl;
    std::cout << std::endl;

    std::cout << compare("Hello", "Hello") << std::endl;
    std::cout << compare("pear", "apple") << std::endl;

    return 0;
}

void string_copy(char* d, char* s){
    for (char *pd = d, *ps = s; *pd++ = *ps++; );
}

int len(const char* s){
    int len = 0;
    
    for (int i = 0; s[i] != '\0'; i++)
        len++;

    return len;
}

int compare(const char* s, const char* t){

    int result = 0;
    int len_s = len(s);
    int len_t = len(t);
    
    if (len_s > len_t){
        result = 1;
    }
    else if (len_s < len_t){
        result = -1;
    }
 
    for (int i = 0; s[i] != '\0' & t[i] != '0'; i++){

        if (s[i] < t[i]){
            result = 1;
            break;
        }
        else if (s[i] > t[i]){
            result = -1;
            break;
        }
    }
    return result;
}