#include <iostream>
class Array
{
    int capacity;
    int lastIndex = -1;
    int *ptr = nullptr;

public:
    Array(int);
    bool isEmpty();
    // find an element in the array
    int findElement(int);
    void traverseArray();
    void insertElement(int, int);
    void deleteElement(int);
    void appendElement(int);
    void editElement(int, int);
    // check if array is full by returning true or false
    bool isFull();
    int getItem(int idx);
    int getCountOfElements();
    // Destructor
    ~Array();
    Array(Array&);
    int getCapacity();
    void operator = (Array&);
};
void Array::operator=(Array &arr){
    capacity = arr.capacity;
    lastIndex = arr.lastIndex;
    delete ptr;
    ptr = new int [capacity];
    for(int i=0 ;i<=lastIndex;i++){
        ptr[i]=arr.ptr[i];
    }
}
int Array::getCapacity(){
    return capacity;
}
Array::Array(Array &arr){
    lastIndex = arr.lastIndex;
    capacity = arr.capacity;
    ptr = new int[capacity];
    for(int i = 0  ;i<= lastIndex;i++){
        ptr[i]= arr.ptr[i];
    }
}
Array::~Array()
{
    delete[] ptr;
}
int Array::getCountOfElements()
{
    return lastIndex + 1;
}
bool Array::isFull()
{
    if (lastIndex + 1 == capacity)
    {
        return true;
    }
    return false;
}
void Array::editElement(int idx, int item)
{
    if (idx < 0 || idx > lastIndex)
    {
        std::cout << "invalid Index";
        return;
    }
    ptr[idx] = item;
}
void Array::appendElement(int item)
{
    if (lastIndex + 1 >= capacity)
    {
        std::cout << "\ncan't append the element ";
        return;
    }
    else
    {
        ptr[++lastIndex] = item;
        return;
    }
}
bool Array::isEmpty()
{
    return lastIndex == -1;
}
void Array::deleteElement(int idx)
{
    // checking if array is empty
    if (isEmpty())
    {
        std::cout << "the array is empty ";
        return;
    }
    if (idx < 0 || idx > lastIndex)
    {
        std::cout << "\n invalid Index";
        return;
    }
    // shifting logic
    if (idx <= lastIndex)
    {
        for (int i = idx; i < lastIndex; i++)
        {
            ptr[i] = ptr[i + 1];
        }
        --lastIndex;
        return;
    }
    //
    // if (idx == lastIndex)
    // {
    //     --lastIndex;
    // }
}
void Array::insertElement(int idx, int item)
{
    if (idx == lastIndex - 1)
    {
        std::cout << "\narray is full ";
        return;
    }
    if (idx < 0 || idx > lastIndex + 1)
    {
        std::cout << "\ninvalid Index";
    }
    // shifting logic
    if (idx <= lastIndex)
    {
        ++lastIndex;
        for (int i = lastIndex; i >= idx; i--)
        {
            ptr[i] = ptr[i - 1];
        }
        ptr[idx] = item;
    }
    if (idx == lastIndex + 1)
    {
        ptr[++lastIndex] = item;
    }
}

int Array::findElement(int element)
{
    if (lastIndex == -1)
    {
        std::cout << "\n array is empty ";
        return 0;
    }
    for (int i = 0; i < lastIndex; i++)
    {
        if (ptr[i] == element)
        {
            std::cout << "element found";
            return i;
        }
    }
    std::cout << "element not found";
    return -1;
}
Array::Array(int capacity)
{
    if (capacity < 0)
    {
        std::cout << "invalid index";
        return;
    }
    this->capacity = capacity;
    this->lastIndex = -1;
    this->ptr = new int[capacity];
}
int Array::getItem(int idx)
{
    if (idx < 0 || idx > lastIndex)
    {
        std::cout << "invalid index";
        return -1;
    }
    return ptr[idx];
}
void Array::traverseArray()
{
    if (lastIndex == -1)
    {
        return;
    }
    std::cout << std::endl;
    for (int i = 0; i <= lastIndex; i++)
    {
        std::cout << ptr[i] << " ";
    }
}
// int main(int argc, char const *argv[])
// {
//     Array arr(7);
//     arr.appendElement(10);
//     arr.insertElement(1, 20);
//     arr.deleteElement(0);
//     arr.findElement(10);
//     std::cout << arr.isEmpty();
//     std::cout << arr.isFull();
//     arr.editElement(0, 400);
//     arr.traverseArray();

//     return 0;
// }
