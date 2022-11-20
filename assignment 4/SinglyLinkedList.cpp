#include <iostream>
class SLL
{
    int data;
    SLL *next;

public:
    SLL *start;
    SLL()
    {
        start = nullptr;
    }
    SLL *createSLL();
    void push_front(int);
    void push_back(int);
    int pop_front();
    int pop_back();
    int isEmpty();
    int search(int);
    void push_after(int);
    void pop_after(int);
    ~SLL();
    void traverse();
    int countNodes();
};
int SLL::countNodes(){
    SLL *temp=start;
    int count=0;
    while(temp){
        ++count;
        temp=temp->next;
    }
    return count;
}
void SLL::push_after(int idx)
{
    int countOfNodes=countNodes();
    if(idx>=0&&idx<countOfNodes)
    for(int i=0;i<countOfNodes;i++){

    }
}
void SLL::pop_after(int idx)
{
}
int SLL::search(int value)
{
    if (start == nullptr)
    {
        return -1;
    }
    SLL *temp = start;
    for (int i = 0; temp != NULL; i++)
    {
        if (temp->data == value)
        {
            return i;
        }
        temp = temp->next;
    }
    return -1;
}
void SLL::traverse()
{
    if (isEmpty())
    {
        std::cout << "\nList is empty ";
        return;
    }
    SLL *temp = start;
    while (temp != nullptr)
    {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
}
SLL::~SLL()
{
    if (!isEmpty())
        while (start != nullptr)
            pop_front();
}
int SLL::isEmpty()
{
    if (start == nullptr)
        return 1;
    return 0;
}
// removes the element from the front and returns the value
int SLL::pop_front()
{
    if (start == nullptr)
    {
        std::cout << "\nList is empty";
        return -1;
    }
    else
    {
        SLL *temp = start;
        start = start->next;
        int val = temp->data;
        delete temp;
        return val;
    }
}
int SLL::pop_back()
{
    if (start == nullptr)
    {
        std::cout << "\nList is empty";
        return -1;
    }
    else
    {
        int value;
        if (start->next == nullptr)
        {
            value = start->data;
            delete start;

            start = nullptr;
            return value;
        }
        SLL *temp = start;
        while (temp->next->next != nullptr)
        {
            temp = temp->next;
        }
        value = temp->next->data;
        delete temp->next;

        temp->next = nullptr;
        return value;
    }
}
void SLL::push_front(int value)
{
    SLL *ptr = createSLL();
    ptr->data = value;
    ptr->next = start;
    if (start == nullptr)
    {
        start = ptr;
        ptr->next = nullptr;
    }
    else
    {
        ptr->next = start;
        start = ptr;
    }
}
void SLL::push_back(int value)
{
    SLL *ptr = createSLL();
    ptr->data = value;
    ptr->next = nullptr;
    if (start == nullptr)
    {
        start = ptr;
        ptr->next = nullptr;
    }
    else
    {
        SLL *temp = start;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = ptr;
    }
}
SLL *SLL::createSLL()
{
    SLL *temp = (SLL *)new SLL;
    return temp;
}
int main(int argc, char const *argv[])
{
    SLL n;
    n.push_back(23);
    std::cout << n.search(23);
    n.traverse();

    return 0;
}
