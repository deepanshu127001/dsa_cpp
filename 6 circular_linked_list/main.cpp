#include <iostream>
struct Node
{
  int data;
  Node *next;
};
class CircularList
{
  Node *last;

public:
  CircularList();
  void insertAtBeg(int);
  void insertAtLast(int);
  void traverse();
  Node *search(int);
  void insertAfter(Node *, int);
  void deleteFirst();
  void deleteEnd();
  void deleteAfter();
};
void CircularList::insertAfter(Node *temp, int data)
{
  Node *node = new Node;
  node->data = data;
  if (last)
  {
    node->next = temp->next;
    temp->next = node;
    if (temp == last)
      last = node;
  }
}
CircularList::CircularList()
{
  last = nullptr;
}
void CircularList::insertAtBeg(int data)
{
  Node *new_node = new Node;
  new_node->data = data;
  if (last)
  {
    new_node->next = last->next;
    last->next = new_node;
  }
  else
  {
    new_node->next = new_node;
    last = new_node;
  }
}
void CircularList::insertAtLast(int data)
{
  Node *new_node = new Node;
  new_node->data = data;
  if (last)
  {
    new_node->next = last->next;
    last->next = new_node;
    last = new_node;
  }
  else
  {
    new_node->next = new_node;
    last = new_node;
  }
}
void CircularList::traverse()
{
  Node *start;
  if (last)
  {
    start = last->next;
    while (start != last)
    {
      std::cout << start->data << " ";
      start = start->next;
    }
    std::cout << start->data << " ";
  }
}
Node *CircularList::search(int data)
{
  if (last)
  {
    Node *temp = last;
    do
    {
      if (temp->data == data)
      {
        return temp;
      }
      temp = temp->next;
    } while (temp != last);
  }
  return nullptr;
}
void CircularList::deleteFirst()
{
  if (last)
  {
    Node *r = last->next;
    if (last->next == last)
    {
      last = nullptr;
    }
    else
    {
      last->next = r->next;
    }
    delete r;
  }
}
void CircularList::deleteEnd()
{
  Node *r = last;
  if (last)
  {
    if (last->next == last)
    {
      delete last;
      last = nullptr;
    }
    else
    {
      Node *temp = last->next;
      while (temp->next != last)
      {
        temp = temp->next;
      }
      temp->next = last->next;
      last=temp;
    }
    delete r;
  }
}
int main()
{
  CircularList c1;
  c1.insertAtBeg(3);
  c1.insertAtBeg(2);
  c1.insertAtBeg(1);
  c1.insertAtLast(4);
  c1.insertAtLast(5);
  c1.insertAtLast(6);
  c1.insertAtLast(7);
  c1.insertAtLast(8);
  c1.insertAfter(c1.search(8), 345);
  c1.traverse();
  c1.deleteEnd();
  c1.traverse();
}