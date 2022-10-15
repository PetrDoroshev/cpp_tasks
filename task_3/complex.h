#include <iostream>
#include <cmath>

class Complex {

public:

    double Re;
    double Im;

    inline Complex(double Re=0, double Im=0){
        this->Re = Re;
        this->Im = Im;
    }
    
    friend inline std::ostream& operator << (std::ostream &s, const Complex &c) {
        return s << c.Re << ' ' << (c.Im <= 0 ? '-' : '+') << ' ' << std::abs(c.Im) << 'i'; 
    }   

    inline Complex operator + (Complex& c){
        return Complex(Re + c.Re, Im + c.Im);
    }

    inline Complex operator - (Complex& c){
        return Complex(Re - c.Re, Im - c.Im);
    }

    inline Complex operator * (Complex& c){
        return Complex(Re * c.Re - Im * c.Im, Re * c.Im + Im * c.Re);
    }

    inline Complex operator / (Complex& c){
        return Complex((Re * c.Re + Im * c.Im) / (Im * Im + c.Im * c.Im), (Im * c.Re - Re * c.Im) / (Im * Im + c.Im * c.Im));
    }

    inline Complex conjugate(){
        return Complex(Re, -1 * Im);
    }

    inline double mod(){
        return sqrt(Re * Re + Im * Im);
    }

    inline double arg(){
        
        double arg;

        if (mod() == 0){
            arg = 0;
        }
        else if (Re > 0){
            arg = atan(Im / Re);
        }
        else if (Re < 0){
            arg = -acos(-1) - atan(Im / Re);
 
            if (Im >= 0)
                arg *= -1;
        }
        else {
            arg = -acos(0);

            if (Im > 0)
                arg *= -1;
        }
        return arg;
    }



};