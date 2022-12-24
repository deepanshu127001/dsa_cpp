#include <iostream>
struct Node {
int data; 
Node *next;
Node *prev;
};
class DLL{
  Node *start=nullptr;
  public:
  void insertAtBeg(int);
  void insertAtEnd(int);
  void insertAfter(int , Node*);
};

Node* createNode(int data){
  Node *temp=new Node;
  temp->data=data;
  temp->next=nullptr;
  temp->prev=nullptr;
  return  temp;
}
void DLL::insertAfter(int data, Node *temp){
  Node *t=createNode(data);
  Node *r=start;
  while(r!=temp){
    r=r->next;
  }
  t->next=r->next;
  t->prev=r;
  r->next->prev=t;
  r->next=t;
}
void DLL::insertAtEnd(int data){
  Node *temp=createNode(data);
  if(start==nullptr){
    start=temp;
  }
  else{
    Node *t=start;
    while(t->next!=nullptr){
      t=t->next;
    }
    t->next=temp;
    temp->prev=t;
  }
}
void DLL::insertAtBeg(int data){
  Node *temp=createNode(data);
  if(start==nullptr){
    start=temp;
  }
  else{
    start->prev=temp;
    temp->next=start;
    start=temp;
  }
}
int main(){
  
}