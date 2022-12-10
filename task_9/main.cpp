#include "binary_heap_opt.h"
#include "binary_heap.h"
#include <chrono>

int main() {

    /*
    int v[10];
    for (int i = 0; i < 10; i++){
        v[i] = i;
    }

    BinaryHeap bh(v, 10);

    for (int i = 0; i < (int)bh; i++){
        std::cout << bh[i] << " ";
    }
    std::cout << std::endl;
    */

    int M = 50;
    int N = 10;

    int v[N];
    for (int i = 0; i < N; i++){
        v[i] = rand() % N;
    }
    int k = 0;

    auto start = std::chrono::steady_clock::now();
    for (int i = 0; i < M; i++){
        BinaryHeap bh(v, N);
        k = bh[0];
    }
    auto stop = std::chrono::steady_clock::now();
    auto dt = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();

    std::cout << "N = " << N << ", " << "dt = " <<  dt << std::endl;
    std::cout << k << std::endl;
    std::cout << std::endl;

    std::cout << "Opt: " << std::endl;
    start = std::chrono::steady_clock::now();
    for (int i = 0; i < M; i++){
        BinaryHeapOpt bh(v, N);
        k = bh[0];
    }
    stop = std::chrono::steady_clock::now();
    dt = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();

    std::cout << "N = " << N << ", " << "dt = " <<  dt << std::endl;
    std::cout << k << std::endl;

    return 0;
}