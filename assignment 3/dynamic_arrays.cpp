#include <cstring>
#include <iostream>
class DynArray
{
    int capacity;
    int lastIndex;
    int *ptr;

public:
    DynArray(int);           // ✅
    void doubleArray();      // ✅
    void halfArray();        // ✅
    int currentCapacity();   // ✅
    bool isEmpty();          // ✅
    void append(int);        // ✅
    void insert(int, int);   //✅
    void deleteElement(int); //✅
    bool isFull();           // ✅
    int getElement(int);
    int getCountOfElements();
    ~DynArray();
    int findElement(int);
    void traverse();
};
DynArray::DynArray(int capacity)
{
    this->capacity = capacity;
    this->lastIndex = -1;
    this->ptr = new int[capacity];
}
void DynArray::doubleArray()
{
    int *temp = new int[capacity * 2];
    for (int i = 0; i <= lastIndex; i++)
    {
        temp[i] = ptr[i];
    }
    capacity=capacity*2;
    delete[] ptr;
    ptr = temp;
}
void DynArray::halfArray()
{
    int *temp = new int[capacity / 2];
    this->capacity /= 2;
    for (int i = 0; i <= lastIndex; i++)
    {
        temp[i] = ptr[i];
    }
    delete[] ptr;
    ptr = temp;
}
int DynArray::currentCapacity()
{
    return capacity;
}
bool DynArray::isEmpty()
{
    return lastIndex == -1;
}
void DynArray::append(int value)
{
    if (isFull())
    {
        doubleArray();
    }
    ptr[++lastIndex] = value;
}
void DynArray::insert(int idx, int value)
{
if (idx < 0 || idx > lastIndex + 1)
    {
        std::cout << "\ninvalid Index";
    if (isFull())
    {
        doubleArray();
    }
    }
    if (idx <= lastIndex)
    {
        ++lastIndex;
        for (int i = lastIndex; i >= idx; i--)
        {
            ptr[i] = ptr[i - 1];
        }
        ptr[idx] = value;
    }
    if (idx == lastIndex + 1)
    {
        ptr[idx] = value;
        ++lastIndex;
    }
}
void DynArray::deleteElement(int idx)
{
    if (isEmpty())
    {
        std::cout << "\n Array is Empty ";
        return;
    }
    if (idx < 0 || idx > lastIndex)
    {
        std::cout << "Invalid Index ";
    }
    if (idx <= lastIndex)
    {
        for (int i = idx; i < lastIndex; i++)
        {
            ptr[i] = ptr[i + 1];
        }
        lastIndex--;
        // if (lastIndex < (capacity / 2))
        if(capacity/2>=lastIndex+1&&capacity>1)
            halfArray();
    }
    // if(idx==lastIndex){
    //     lastIndex--;
    //     if( lastIndex<(capacity/2))
    //     halfArray();
    // }
}
bool DynArray::isFull()
{
    return lastIndex + 1 == capacity;
}
int DynArray::getElement(int idx)
{
    if (idx > 0 && idx <= lastIndex)
    {
        return ptr[idx];
    }
}
int DynArray::getCountOfElements()
{
    return lastIndex + 1;
}
DynArray::~DynArray()
{
    delete[] ptr;
}
int DynArray::findElement(int element)
{
    if (isEmpty())
        return -1;
    for (int i = 0; i <= lastIndex; i++)
    {
        if (ptr[i] == element)
        {
            return i;
        }
    }
    return -1;
}
void DynArray::traverse()
{
    if (isEmpty())
        return;
    for (int i = 0; i <= lastIndex; i++)
    {
        std::cout << ptr[i] << " ";
    }
}
int main(int argc, char const *argv[])
{
    DynArray arr(5);
    // arr.append(12);
    // arr.append(12);
    // arr.append(12);
    // arr.append(12);
    // arr.append(12);
    // std::cout<<arr.currentCapacity()<<std::endl;
    // arr.traverse();
    // std::cout<<std::endl;
    // arr.append(0);
    // std::cout<<arr.currentCapacity()<<std::endl;
    // arr.traverse();
    arr.insert(0, 100);
    arr.insert(1, 101);
    arr.insert(2, 102);
    arr.insert(3, 103);
    arr.insert(4, 104);
    arr.insert(5, 104);
    arr.append(103);
    arr.append(102);
  
    // arr.insert(5, 198760);
    // arr.insert(1, 20);
    arr.traverse();
    std::cout << arr.currentCapacity();

    return 0;
}
