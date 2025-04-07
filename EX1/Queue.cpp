//dael12345@gmail.com
#include "Queue.hpp"

namespace graph {

 /**
 * Constructor: creates a queue with a fixed capacity.
 *
 * @param cap Maximum number of elements the queue can hold.
 */
Queue::Queue(int cap) {
    capacity = cap;
    data = new int[cap];
    front = rear = size = 0;
}

/**
 * Destructor: frees the memory used by the queue.
 */
Queue::~Queue() {
    delete[] data;
}

/**
 * Checks if the queue is empty.
 *
 * @return true if the queue is empty, false otherwise.
 */
bool Queue::isEmpty() const {
    return size == 0;
}

/**
 * Adds a new value to the end of the queue.
 *
 * @param value The value to insert.
 * @throws If the queue is full (overflow).
 */
void Queue::enqueue(int value) {
    if (size == capacity) throw "Queue overflow!";
    data[rear] = value;
    rear = (rear + 1) % capacity;
    ++size;
}

 /**
 * Removes and returns the value at the front of the queue.
 *
 * @return The value that was at the front of the queue.
 * @throws If the queue is empty.
 */
int Queue::dequeue() {
    if (isEmpty()) throw "Queue is empty";
    int value = data[front];
    front = (front + 1) % capacity;
    --size;
    return value;
}

}