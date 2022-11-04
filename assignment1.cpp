#include <iostream>
using namespace std;
// 1 define a class Array to implement array data structure with member variables to store capacity of array , last index
class Array
{
    int capacity;
    int lastIndex = -1;
    int *ptr;

public:
    // define a parameterised constructor to create an array of specified size
    Array(int capacity);
    // add a method to check whether an array is empty or not returning true or false
    string isEmpty();
    // define a method to append a new element in the array
    void appendElement(int item);
    // define a method to insert a new element at specified index
    int insertElement(int idx, int item)
    {
        //checking if  array is full or not 
        if(lastIndex==capacity-1){
                  std::cout<<"array is full ";
                  return 0;
        }
        if(idx<0||idx>lastIndex+1){
            std::cout<<"invalid index ";
            return 0;
        }
        if(idx <=lastIndex){
            ++lastIndex;
            for(int i=lastIndex;i>=idx;i--){
                ptr[i]=ptr[i-1];
            }
            ptr[idx]=item;
            return 1;
        }
        if(idx==lastIndex+1){
            ++lastIndex;
            ptr[lastIndex]=item;
            return 1;
        }

        }
    // defina a method to edit an element at specified index
    void editElement(int idx, int item)
    {
        if (idx < 0 || idx > capacity)
        {
            cout << endl
                 << "index out of range" << item;
        }
        else
        {
            ptr[idx] = item;
        }
    }
    // define a method to delete an element at specified index
    void deleteElement(int idx)
    {
    }
    // define a method to check whether the array is full
    bool isFull()
    {
        if (lastIndex + 1 == capacity)
        {
            return true;
        }
        return false;
    }
    // define a method to getElement at specified Index
    int getElement(int idx)
    {
        if (idx < 0 || idx > capacity || idx > lastIndex)
        {
            cout << "invalid index";
            return -1;
        }
        return ptr[idx];
    }
    // define a method to count number of elements present in an array
    int countElements()
    {
        return lastIndex + 1;
    }
    // define a destructor to deallocate the memory of an array
    ~Array()
    {
        // cout<<"memory freed";
        delete ptr;
    }
    // define a method to find an element in the array . Return index if the element found otherwise return -1
    int findElement(int item)
    {
        for (int i = 0; i <= lastIndex; i++)
        {
            if (item == ptr[i])
            {
                cout << "element found @" << i;
                return i;
            }
        }
        return -1;
    }
    // traverse array
    void traverseArray()
    {
        for (int i = 0; i <= lastIndex; i++)
        {
            cout << ptr[i] << " ";
        }
    }
};

Array::Array(int capacity)
{
    if (capacity < 1)
    {
        cout << endl
             << "Enter a  valid range";
        return;
    }
    ptr = new int[capacity];
    this->capacity = capacity;
}
string Array::isEmpty()
{
    if (this->lastIndex == -1)
        return "true";
    else
        return "false";
}
void Array::appendElement(int item)
    {
        if (this->lastIndex + 1 < capacity)
        {
            ptr[++lastIndex] = item;
        }
        else
        {
            cout << endl
                 << "index out of range for value " << item;
        }
    }

int main(int argc, char const *argv[])
{
    Array arr(5);

    arr.appendElement(23);
    arr.insertElement(1,34);
    arr.insertElement(0,10);
    arr.insertElement(0,10);
    arr.insertElement(0,10);
    arr.insertElement(0,10);
    arr.traverseArray();
    return 0;
}
