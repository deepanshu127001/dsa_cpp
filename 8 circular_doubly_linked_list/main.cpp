#include <iostream>
struct Node {
    int data;
    Node *prev;
    Node *next;
};
class CDLL{
    Node *start;
    public :
    CDLL();
    void insertAtBegining(int);
    void insertAtEnd(int);
    Node* search(int);
    void insertAfter(Node*,int);
    void deleteFirst();
    void deleteLast();
    void deleteNode(Node*);
    void traverse();
    // ~CDLL();
};
void CDLL::traverse(){
    if(start==nullptr){
        std::cout<<"list is empty ";
    }
    else{
        Node *temp=start;
        do{
            std::cout<<temp->data<<" ";
            temp=temp->next;
        }while(temp!=start);
    }
}
CDLL::CDLL(){
    start = nullptr;
}
void CDLL::insertAtBegining(int data){
    Node *node=new Node;
    node -> data = data;
    if(start==nullptr){
        node->prev=node;
        node->next=node;
        start = node;
    }
    else{
        node->next=start;
        node->prev=start->prev;
        start->prev->next=node;
        start->prev=node;
        start=node;
    }
}
void CDLL::insertAtEnd(int data){
     Node *node=new Node;
    node -> data = data;
    if(start==nullptr){
        node->prev=node;
        node->next=node;
        start = node;
    }
    else{
        node->next =start;
        node->prev=start->prev;
        start->prev->next=node;
        start->prev = node;
    }
}
int main(int argc, char const *argv[])
{
    CDLL l1;
    l1.insertAtBegining(5);
    l1.insertAtBegining(4);
    l1.insertAtBegining(3);
    l1.insertAtBegining(2);
    l1.insertAtBegining(1); 
    l1.insertAtEnd(6);
    l1.traverse();
    return 0;
}
