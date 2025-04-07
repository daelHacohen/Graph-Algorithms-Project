//dael12345@gmail.com
#ifndef QUEUE_HPP
#define QUEUE_HPP

namespace graph {

class Queue {
private:
    int* data;
    int front, rear, size, capacity;

public:
    Queue(int cap);
    ~Queue();
    bool isEmpty() const;
    void enqueue(int value);
    int dequeue();
};

} 

#endif 