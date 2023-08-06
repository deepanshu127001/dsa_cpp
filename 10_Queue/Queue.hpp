#include <iostream>
#include <memory>
class Queue
{
    Queue(uint32_t);
    ~Queue();
    bool isFull();
    bool isEmpty();
    void insert(int);
    int getRear();
    int getFront();
    private:
        uint32_t capacity;
        uint32_t front;
        uint32_t rear;
        std::unique_ptr<int[]> ptr;
};
