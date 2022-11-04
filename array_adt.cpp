#include <iostream>
class Array
{
    int capacity;
    int lastIndex = -1;
    int *ptr = nullptr;

public:
    Array(int capacity)
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
    bool isEmpty()
    {
        if (lastIndex == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void appendElement(int item)
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
    void insertElement(int idx, int item)
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
    void editElement(int idx, int item)
    {
        if (idx < 0 || idx > lastIndex)
        {
            std::cout << "invalid Index";
            return;
        }
        ptr[idx] = item;
    }
    void deleteElement(int idx)
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
        if (idx == lastIndex)
        {
            --lastIndex;
        }
    }
    // check if array is full by returning true or false
    bool isFull()
    {
        if (lastIndex + 1 == capacity)
        {
            return true;
        }
        return false;
    }

    int getItem(int idx)
    {
        if (idx < 0 || idx > lastIndex)
        {
            std::cout << "invalid index";
            return -1;
        }
        return ptr[idx];
    }
    int getCountOfElements(){
        return lastIndex+1;
    }
    //Destructor
    ~Array(){
        delete []ptr;
    }
    //find an element in the array 
    int findElement(int element){
        if(lastIndex==-1){
            std::cout<<"\n array is empty ";
            return 0;
        }
        for(int i=0;i<lastIndex;i++){
            if(ptr[i]==element){
                std::cout<<"element found";
                return i;
            }
        }
                std::cout<<"element not found";
        return -1;
    }
    void traverseArray(){
        if(lastIndex==-1){
            return;
        }
        std::cout<<std::endl;
        for(int i=0;i<=lastIndex;i++){
            std::cout<<ptr[i]<<" ";
        }
    }
};
int main(int argc, char const *argv[])
{
    Array arr(7);
    arr.appendElement(10);
    arr.insertElement(1,20);
    arr.deleteElement(0);
    arr.findElement(10);
    std::cout<<arr.isEmpty();
    std::cout<<arr.isFull();
    arr.editElement(0,400);
    arr.traverseArray();
    return 0;
}

