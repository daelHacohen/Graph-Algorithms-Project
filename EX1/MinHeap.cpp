//dael12345@gmail.com
#include "MinHeap.hpp"

namespace graph {

 /**
 * Constructor: creates a min-heap with a given capacity.
 *
 * @param n The maximum number of elements the heap can hold.
 */
MinHeap::MinHeap(int n) {
    capacity = n;
    heap = new Node[n];
    pos = new int[n];
    size = 0;
}

/**
 * Destructor: frees the memory used by the heap and position array.
 */
MinHeap::~MinHeap() {
    delete[] heap;
    delete[] pos;
}

 /**
 * Swaps two nodes in the heap and updates their positions.
 *
 * @param i Index of the first node.
 * @param j Index of the second node.
 */
void MinHeap::swap(int i, int j) {
    Node temp = heap[i];
    heap[i] = heap[j];
    heap[j] = temp;

    pos[heap[i].vertex] = i;
    pos[heap[j].vertex] = j;
}

 /**
 * Moves the node at index i up in the heap until the heap property is restored.
 *
 * @param i Index of the node to move up.
 */
void MinHeap::heapifyUp(int i) {
    while (i > 0 && heap[i].dist < heap[(i - 1) / 2].dist) {
        swap(i, (i - 1) / 2);
        i = (i - 1) / 2;
    }
}

/**
 * Moves the node at index i down in the heap until the heap property is restored.
 *
 * @param i Index of the node to move down.
 */
void MinHeap::heapifyDown(int i) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int smallest = i;

    if (left < size && heap[left].dist < heap[smallest].dist)
        smallest = left;
    if (right < size && heap[right].dist < heap[smallest].dist)
        smallest = right;

    if (smallest != i) {
        swap(i, smallest);
        heapifyDown(smallest);
    }
}

/**
 * Inserts a new node into the heap with the given vertex and distance.
 *
 * @param v The vertex to insert.
 * @param dist The distance value of the vertex.
 * @throws If the heap is full.
 */
void MinHeap::insert(int v, int dist) {
    if (size >= capacity)
        throw "Heap overflow!";
    heap[size] = {v, dist};
    pos[v] = size;
    heapifyUp(size);
    ++size;
}

 /**
 * Checks if the heap is empty.
 *
 * @return true if the heap is empty, false otherwise.
 */
bool MinHeap::isEmpty() const {
    return size == 0;
}

 /**
 * Removes and returns the vertex with the smallest distance.
 *
 * @return The vertex with the minimum distance.
 */
int MinHeap::extractMin() {
    int v = heap[0].vertex;
    heap[0] = heap[--size];
    pos[heap[0].vertex] = 0;
    heapifyDown(0);
    return v;
}

/**
 * Updates the distance of a vertex to a smaller value.
 *
 * @param v The vertex to update.
 * @param newDist The new smaller distance.
 * @throws If the vertex is not currently in the heap.
 */
void MinHeap::decreaseKey(int v, int newDist) {
    if (!contains(v))
    throw "Vertex not found in heap";

    int i = pos[v];
    heap[i].dist = newDist;
    heapifyUp(i);
}

/**
 * Checks if a given vertex is currently in the heap.
 *
 * @param v The vertex to check.
 * @return true if the vertex is in the heap, false otherwise.
 */
bool MinHeap::contains(int v) const {
    return pos[v] < size;
}

 /**
 * Returns the current distance of a given vertex in the heap.
 *
 * @param v The vertex to query.
 * @return The distance value of the vertex.
 */
int MinHeap::getDist(int v) const {
    return heap[pos[v]].dist;
}

}