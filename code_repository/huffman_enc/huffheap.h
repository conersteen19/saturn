// Code written by Aaron Bloomfield, 2014
// Released under a CC BY-SA license
// This code is part of the https://github.com/aaronbloomfield/pdr repository

#ifndef HUFFHEAP_H
#define HUFFHEAP_H

#include <vector>
#include "huffnode.h"
using namespace std;

class huffheap {
public:
    huffheap();
    ~huffheap();

    void insert(huffnode* x);
    huffnode* findMin();
    huffnode* deleteMin();
    unsigned int size();
    void makeEmpty();
    bool isEmpty();
    void print();

private:
    vector<huffnode*> heap;
    unsigned int heap_size;

    void percolateUp(int hole);
    void percolateDown(int hole);
};

#endif
