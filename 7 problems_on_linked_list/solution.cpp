#include "../4 singly_linked_list/SinglyLinkedList.cpp"
#include <iostream>
using namespace std;
bool isCycle(SLL &obj){
    SLL *slow = obj.getHead();
    SLL *fast= obj.getHead();
    while(fast->next&&fast->next->next){
        fast = fast->next->next;
        slow = slow->next;
        if(slow == fast)
            return true;
    }
    return false;
}
int lengthOfCycle(SLL &obj){
    if(isCycle(obj)){
        SLL *slow = obj.getHead();
        SLL *fast = obj.getHead();
        while(slow!=fast){
            fast = fast->next->next;
            slow = slow->next;
        }
        int count =0;
        while(fast->next!=slow){
            fast = fast->next;
            ++count;
        }
        return count;
    }
    return 0;
}