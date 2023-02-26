#include "../1 array_adt/array_adt.cpp"
#include <iostream>
class Stack:private Array{
public:
    Stack(int);
    void push (int);
    int peek();
    void pop();
    ~Stack();
    bool isFull();
    bool isEmpty();
    void reverse(Stack&);
    Stack(Stack&);//copy constructor for deep copy
    int getStackSize();
    void operator=(Stack &s1);
};
void Stack::operator=(Stack &s){
    Array::operator=(s);
}
int Stack::getStackSize(){
    return getCapacity();
}
bool Stack::isEmpty(){
    return Array::isEmpty();
}
bool Stack::isFull(){
    return Array::isFull();
}
Stack::Stack(int capacity):Array(capacity){}
void Stack::push(int element){
    if(isFull()){
        std::cout<<"stack is full";
    }
    else
    appendElement(element);
}
int Stack::peek(){
    if(!isEmpty()){
      return   getItem(getCountOfElements()-1);
    }
    else{
        std::cout<<"stack is empty";
    }
    return 0;
}
void Stack::pop(){
    if(isEmpty())
        std::cout<<"stack is empty";
    else
        deleteElement(getCountOfElements()-1);
}
Stack::~Stack(){

}
void Stack::reverse(Stack &s1){
    Stack s2(s1.getStackSize());
    while(!s1.isEmpty()){
        s2.push(s1.peek());
        s1.pop();
    }
    s1=s2;
}
Stack::Stack(Stack &s):Array(s){};
int main(int argc, char const *argv[])
{
    Stack s1(5);
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.reverse(s1);
    std::cout<<s1.peek();
    return 0;
}
