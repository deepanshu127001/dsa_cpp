struct Node {
    int data;
    Node *next;
};
class CLL{
    Node *last;
    public:
    CLL();
    void insertAtBeg(int);
};
CLL::CLL(){
    last = nullptr;
}
void CLL::insertAtBeg(int data){
    Node *node=new Node;
    if(last){

    }
    else{
        node->next=node;
    }
}
