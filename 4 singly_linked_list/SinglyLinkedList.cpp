#include <iostream>
class SLL
{

public:
    int data;
    SLL *next;
    SLL *start;
    SLL()
    {
        start = nullptr;
    }
    SLL *createNode();
    void push_front(int);
    void push_back(int);
    int pop_front();
    int pop_back();
    int isEmpty();
    int search(int);
    void push_after(int,int);
    void pop_after(int);
    ~SLL();
    void traverse();
    int countNodes();
    SLL* getHead();
};
SLL* SLL::getHead(){
    return start;
}
int SLL::countNodes(){
    SLL *temp=start;
    int count=0;
    while(temp){
        ++count;
        temp=temp->next;
    }
    return count;
}
void SLL::push_after(int value,int idx)
{
    int count=countNodes();
    SLL *newNode=createNode();
    newNode->data=value;
    newNode->next=NULL;
    if(count>0&&idx<count){
            SLL *slow=start;
            SLL*fast=slow->next;
        for(int i=0;i<idx;i++){
            slow=fast;
            fast=fast->next;
        }
        newNode->next=fast;
        slow->next=newNode;
    }
    else{
        std::cout<<"\n invalid index";
    }
}
void SLL::pop_after(int idx)
{

    if(idx>0&&idx<countNodes()){
        SLL *slow=start,*fast=slow->next;
        for (int i = 0; i <idx; i++)
        {
            std::cout<<"moving forward";
            slow=fast;
            fast=fast->next;
        }
        slow->next=fast->next;
        delete fast;
    }
    else{
        std::cout<<"\ninvalid index";
    }
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
    SLL *ptr = createNode();
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
    SLL *ptr = createNode();
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
SLL *SLL::createNode()
{
    SLL *temp = (SLL *)new SLL;
    return temp;
}
int main(int argc, char const *argv[])
{
    SLL n;
    n.push_back(1);
    n.push_back(2);
    n.push_back(3);
    n.push_back(4);
    n.push_after(50,1);
    n.traverse();
    n.pop_after(2);
    n.traverse();
    return 0;
}
