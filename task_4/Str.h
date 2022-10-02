#include <string.h>
#include <cstring>

class Str {

    char* str_array;

public:

    Str() {str_array = new char[1] {0};}
    ~Str() {delete[] str_array;}

    Str(const char* p) {
        
        if (p) {
            str_array = new char[strlen(p) + 1];
            strcpy(str_array, p);
            
        }
        else {
            str_array = new char[1] {0};
        }

    }

    inline Str(const Str& s){
        str_array = new char[strlen(s.str_array) + 1];
        strcpy(str_array, s.str_array);
    }

    inline operator const char*() const { return str_array; }

    inline const Str& operator = (const Str& s) {

        if (&s  == this)
            return *this;
        
        delete[] str_array;

        str_array = new char[strlen(s.str_array) + 1];
        strcpy(str_array, s.str_array);

        return *this;


    }

    inline Str& operator += (const char* sz){

        char* tmp = str_array;
        str_array = new char [strlen(sz) + strlen(tmp) + 1];

        strcpy(str_array, tmp);
        strcat(str_array, sz);

        delete[] tmp;
        
        return *this;
    }

    inline Str operator + (const char* sz) const{
        
        Str new_str = *this;
        new_str += sz;
        return new_str;

    }
};