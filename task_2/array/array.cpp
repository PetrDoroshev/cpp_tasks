#include <iostream>

void rotate(int a[], int n, bool clockwise);

int main() {

    int a[5] = {1, 2, 3, 4, 5};

    for (int i = 0; i < 5; i++){
       std::cout << a[i] << ' ';
    }
    std::cout << std::endl; 

    rotate(a, 5, true);

    for (int *p = a; p - a < 5; p++){
        std::cout << *p << ' ';
    }
    std::cout << std::endl;

    return 0;
}

void rotate(int a[], int n, bool clockwise){

    if (!clockwise){

        int* p = a + 1;
        int x = a[0];

        while(p - a < n){
            *(p - 1) = *p;
            p++;
        }

        *(p - 1) = x;
    }
    else {

        int* p = a + n - 2;
        int x = a[n - 1];

        while (p - a > - 1){  
            *(p + 1) = *p;
            p--;
        }
        *(p + 1) = x;
    }
}