#include "Queue.hpp"

Queue::Queue(uint32_t cap) : capacity(cap),
                             front(-1),
                             rear(-1),
                             ptr(std::make_unique<int[]>(capacity)){};

Queue::~Queue()
{
    std::cout << "destructed";
}
bool Queue::isFull()
{
    return ((front == 0 && rear == capacity - 1) || rear + 1 == front);
}
bool Queue::isEmpty()
{
    return rear == -1;
}
int Queue::getRear()
{
    if(!isEmpty())
        return ptr[rear];
    else
        return -1;
}
int Queue::getFront()
{
    if(!isEmpty())
        return ptr[front];
    return -1;
}
void Queue::insert(int data)
{
    // case where insertion is not possible
    if (isFull())
    {
        std::cout << "Queue Overflow " << std::endl;
    }
    else if (isEmpty())
    {
        front = 0;
        rear = 0;
        ptr[rear] = data;
    }
    else if (rear == capacity - 1)
    {
        rear = 0;
        ptr[rear] = data;
    }
    else
    {
        ptr[rear]=data;
    }
}
