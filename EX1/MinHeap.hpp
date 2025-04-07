//dael12345@gmail.com
#ifndef MINHEAP_HPP
#define MINHEAP_HPP

namespace graph {

class MinHeap {
private:
    struct Node {
        int vertex;
        int dist;
    };

    Node* heap;
    int* pos;
    int size;
    int capacity;

    void swap(int i, int j);
    void heapifyUp(int i);
    void heapifyDown(int i);

public:
    MinHeap(int n);
    ~MinHeap();
    void insert(int v, int dist);
    bool isEmpty() const;
    int extractMin();
    void decreaseKey(int v, int newDist);
    bool contains(int v) const;
    int getDist(int v) const;
};

} 

#endif