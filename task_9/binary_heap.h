#include <exception>
#include <iostream>
#include <vector>


class BinaryHeap {
    std::vector<int> heap;


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

        int len = heap.size();
        for (int i = len / 2; i >= 0; i--){
            fixHeap(i, len);
        }
    }

public:

    BinaryHeap(int* values, int n): heap(n) {

        for (int i = 0; i < n; i++)
            heap[i] = values[i];

        buildHeap();
        
    }

    operator int const() { return heap.size(); }

    int operator[] (std::size_t i) { 

        if (i < 0 || i >= heap.size())
            throw std::out_of_range("index out of range");

        return heap[i];    
    }
};