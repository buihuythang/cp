#include "PriorityQueue.h"



MaxHeap::MaxHeap()
    : key(1, 0) {
}


void MaxHeap::insert(int k) {
    key.push_back(k);
    swim(key.size()-1);
}


int MaxHeap::pop() {
    int m = key[1];
    swap(key[key.size()-1], key[1]);
    key.pop_back();
    sink(1);

    return m;
}


void MaxHeap::swim(int child) {
    int parent = child >> 1;
    while (parent >= 1 && key[child] > key[parent]) {
        swap(key[child], key[parent]);
        child = parent;
        parent = child >> 1;
    }
}


void MaxHeap::sink(int parent) {
    int child = parent<<1;
    int sz = key.size() - 1;
    while (child < sz) {
        if (key[child] < key[child+1]) ++child;
        if (key[parent] >= key[child]) break;
        swap(key[parent], key[child]);
        parent = child;
        child = parent<<1;
    }
}


bool MaxHeap::empty() {
    return key.size() == 1;
}


size_t MaxHeap::size() {
    return key.size() - 1;
}


void MaxHeap::print() {
    for (auto k: key) {
        cout << k << ' ';
    }
    cout << endl;
}



MinHeap::MinHeap()
    : key(1, 0) {
}


void MinHeap::insert(int k) {
    key.push_back(k);

    swim(key.size()-1);
}


int MinHeap::pop() {
    int m = key[1];
    swap(key[1], key[key.size()-1]);
    key.pop_back();
    sink(1);

    return m;
}


void MinHeap::swim(int child) {
    int parent = child>>1;
    while (parent >= 1 && key[parent] > key[child]) {
        swap(key[parent], key[child]);

        child = parent;
        parent = child>>1;
    }
}


void MinHeap::sink(int parent) {
    int child = parent<<1;
    int sz = key.size() - 1;
    while (child < sz) {
        if (key[child] > key[child+1]) ++child;
        if (key[parent] <= key[child]) break;

        swap(key[child], key[parent]);
        parent = child;
        child = parent<<1;
    }
}


int MinHeap::size() {
    return key.size() - 1;
}


bool MinHeap::empty() {
    return key.size() == 1;
}

void MinHeap::print() {
    for (auto k: key) {
        cout << k << ' ';
    }
    cout << endl;
}
