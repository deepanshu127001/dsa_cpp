#include <iostream>
struct Node{
    int data;
    Node *prev;
    Node *next;
};
class CDLL{
    Node *last;
    public:
    CDLL();
    void insertAtBeg(int);
    void traverse();
};
CDLL::CDLL(){
    last = nullptr;
}
void CDLL::insertAtBeg(int data){
    Node *new_node = new Node;
    new_node->data = data;
    if(last == nullptr){
        last = new_node ;
        new_node->prev=new_node;
        new_node->next=new_node;
    }
    else{

    }
}
void CDLL::traverse(){
    if(last){
        Node *temp=last;
        do{
            std::cout<<temp -> data;
            temp = temp->next;
        }while(temp!=last);
    }
}
int main(int argc, char const *argv[])
{
    
    return 0;
}
