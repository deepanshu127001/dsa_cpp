#include <iostream>
class Node
{
    int data;
    Node *next;

public:
    Node *start = NULL;

    Node *createNode();
    void push_front(int);
    void push_back(int);
    int pop_front();
    int pop_back();
    int isEmpty();
    ~Node();
    void Traverse();

};
void Node::Traverse(){
    if(isEmpty()){
        std::cout<<"\nList is empty ";
        return ;
    }
    Node *temp=start;
    while(temp!=NULL){
        std::cout<<temp->data<<" ";
        temp=temp->next;
    }
}
Node::~Node(){
    if(!isEmpty()){
        while(start!=NULL){
            pop_front();
        }
    }
}
int Node::isEmpty(){
    if(start==NULL){
        return 1;
    }
    return 0;
}
// removes the element from the front and returns the value
int Node::pop_front()
{
    if (start == NULL)
    {
        std::cout << "\nList is empty";
        return -1;
    }
    else
    {
        Node *temp = start;
        start = start->next;
        int val = temp->data;
        delete temp;
        return val;
    }
}
int Node::pop_back()
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
        Node *temp = start;
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
void Node::push_front(int value)
{
    Node *ptr = createNode();
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
void Node::push_back(int value)
{
    Node *ptr = createNode();
    ptr->data = value;
    ptr->next = NULL;
    if (start == NULL)
    {
        start = ptr;
        ptr->next = NULL;
    }
    else
    {
        Node *temp = start;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = ptr;
    }
}
Node *Node::createNode()
{
    Node *temp = (Node *)new Node;
    return temp;
}
int main(int argc, char const *argv[])
{
    Node n;
    n.push_back(23);
    n.push_back(24);
    n.push_back(25);
    n.push_back(25);
    n.push_front(22);
    n.pop_back();
    n.Traverse();
  
    return 0;
}
