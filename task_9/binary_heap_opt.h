#include <exception>
#include <iostream>
#include <vector>


class BinaryHeapOpt {

    int* heap;
    int size;


    void swap(int& a, int& b){
        int tmp = a;
        a = b;
        b = tmp;
    }

    void fixHeap(int i, int len) {

        int left = 2 * i + 1;
        int right = left + 1;
        int largest;

        if (left < len && heap[left] > heap[i])
            largest = left;
        else 
            largest = i;

        if (right < len && heap[right] > heap[largest])
            largest = right;

        if (largest != i) {	
            swap(heap[i], heap[largest]);
            fixHeap(largest, len);
        }
    }

    void buildHeap() {

        for (int i = size / 2; i >= 0; i--){
            fixHeap(i, size);
        }
    }

public:

    BinaryHeapOpt(int* values, int n) {

        size = n;
        heap = new int[size];

        for (int i = 0; i < n; i++)
            heap[i] = values[i];

        buildHeap();
        
    }

    ~BinaryHeapOpt() { delete[] heap; }

    operator int const() { return size; }

    int operator[] (std::size_t i) { 

        if (i < 0 || i >= size)
            throw std::out_of_range("index out of range");

        return heap[i];    
    }
};