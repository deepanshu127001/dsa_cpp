#include <iostream>
using namespace std;
struct Node {
  Node *prev;
  Node *next;
  int data;
};
class DLL {
  Node *start;

public:
  DLL();
  void insertAtBeg(int);
  void insertAtEnd(int);
  Node *search(int); // searches data and returns address of the node
  void insertAfter(Node *, int);
  void deleteFromBeg();
  void deleteFromEnd();
  void deleteSpecificNode(Node *);
  Node *createNode(int data);
  void traverse();
  ~DLL();
};
DLL::~DLL(){
  while(start){
    deleteFromBeg();
  }
}
DLL::DLL() { start = nullptr; }
Node *DLL::createNode(int data) {
  Node *node = new Node;
  node->data = data;
  node->prev = nullptr;
  node->next = nullptr;
  return node;
}
void DLL::insertAtBeg(int data) {
  Node *node = createNode(data);
  if (start == nullptr) {
    start = node;
  } else {
    node->next = start;
    start->prev = node;
    start = node;
  }
}
void DLL::insertAtEnd(int data) {
  Node *node = createNode(data);
  if (start == nullptr) {
    start = node;
  } else {
    Node *temp = start;
    while (temp->next != nullptr) {
      temp = temp->next;
    }
    temp->next = node;
    node->prev = temp;
  }
}
Node *DLL::search(int data) {
  if (start == nullptr) {
    std::cout << "list is empty , Nothing to search" << std::endl;
    return nullptr;
  } else {
    Node *temp = start;
    while (temp != nullptr) {
      if (temp->data == data) {
        // std::cout << "value found";
        return temp;
      }
      temp = temp->next;
    }
  }
  std::cout << "value not found " << std::endl;
  return nullptr;
}
void DLL::insertAfter(Node *node, int data) {
  Node *traverser = start;
  Node *new_node = createNode(data);
  if (node == nullptr) {
    std::cout
        << "node value is empty , must contain one element with perfect match "
        << std::endl;
    return;
  } else {
    while (traverser != node) {
      traverser = traverser->next;
    }
    if (traverser != nullptr) {
      new_node->prev = traverser;
      new_node->next = traverser->next;
      if(traverser->next)//if(traverser->next!=null)
      traverser->next->prev = new_node;
      traverser->next = new_node;
    } else {
      std::cout << "cant insert at end";
    }
  }
}
void DLL::traverse() {
  if (start == nullptr) {
    std::cout << "list is empty , can't traverse ";
    return;
  } else {
    Node *temp_node = start;
    while (temp_node != nullptr) {
      std::cout << temp_node->data << " ";
      temp_node = temp_node->next;
    }
  }
  std::cout<<"\n";
}
void DLL::deleteFromEnd() {
  if (start->next == nullptr) {
    delete start;
    start = nullptr;
  } else {
    Node *temp = start;
    while (temp->next->next != nullptr) {
      temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
  }
}
void DLL::deleteFromBeg() {
  if (start == nullptr) {
    std::cout << "\n list is empty ";
  }
  if (start->next == nullptr) {
    delete start;
    start = nullptr;
  } else {
    Node *temp = start->next;
    temp->prev = nullptr;
    delete start;
    start = temp;
  }
}
void DLL::deleteSpecificNode(Node *node_to_be_deleted){
 Node *temp=start;
  while(temp!=node_to_be_deleted){
    temp=temp->next;
  }
  if(temp->prev)
    temp->prev->next=temp->next;
  else
    start=temp->next;
  if(temp->next)
    temp->next->prev=temp->prev;
  delete temp;
}
int main() {
  DLL l1;
  l1.insertAtBeg(3);
  l1.insertAtBeg(2);
  l1.insertAtBeg(1);
  l1.insertAtEnd(4);
  l1.insertAtEnd(5);
  // l1.search(1);
  l1.insertAfter(l1.search(4), 300);
    l1.traverse();
  l1.deleteFromEnd();
  l1.traverse();
  // l1.deleteFromBeg();
  l1.deleteSpecificNode(l1.search(300));
  l1.traverse();
  return 0;
}