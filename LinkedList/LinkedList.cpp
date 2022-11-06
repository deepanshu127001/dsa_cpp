#include <iostream>
class SLL
{
    int data;
    SLL *next;

public:
    SLL *start = NULL;

    SLL *createSLL();
    void push_front(int);
    void push_back(int);
    int pop_front();
    int pop_back();
    int isEmpty();
    ~SLL();
    void Traverse();

};
void SLL::Traverse(){
    if(isEmpty()){
        std::cout<<"\nList is empty ";
        return ;
    }
    SLL *temp=start;
    while(temp!=NULL){
        std::cout<<temp->data<<" ";
        temp=temp->next;
    }
}
SLL::~SLL(){
    if(!isEmpty()){
        while(start!=NULL){
            pop_front();
        }
    }
}
int SLL::isEmpty(){
    if(start==NULL){
        return 1;
    }
    return 0;
}
// removes the element from the front and returns the value
int SLL::pop_front()
{
    if (start == NULL)
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
    if (start == NULL)
    {
        std::cout << "\nList is empty";
        return -1;
    }
    else
    {
        int value;
        if (start->next == NULL)
        {
            value = start->data;
            delete start;
            start = NULL;
            return value;
        }
        SLL *temp = start;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        value = temp->next->data;
        delete temp->next;
        temp->next = NULL;
        return value;
    }
}
void SLL::push_front(int value)
{
    SLL *ptr = createSLL();
    ptr->data = value;
    ptr->next = start;
    if (start == NULL)
    {
        start = ptr;
        ptr->next = NULL;
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
    ptr->next = NULL;
    if (start == NULL)
    {
        start = ptr;
        ptr->next = NULL;
    }
    else
    {
        SLL *temp = start;
        while (temp->next != NULL)
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
    n.push_back(24);
    n.push_back(25);
    n.push_back(25);
    n.push_front(22);
    n.pop_back();
    n.Traverse();
  
    return 0;
}
