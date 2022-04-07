#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <bits/stdc++.h>

using namespace std;


class MaxHeap {
public:
    MaxHeap();
    void insert(int k);
    int pop();
    void swim(int child);
    void sink(int parent);
    bool empty();
    size_t size();
    void print();

private:
    vector<int> key;
};


class MinHeap {
public:
    MinHeap();
    void insert(int k);
    int pop();
    void swim(int child);
    void sink(int parent);
    int size();
    bool empty();
    void print();

private:
    vector<int> key;
};


#endif // PRIORITYQUEUE_H
