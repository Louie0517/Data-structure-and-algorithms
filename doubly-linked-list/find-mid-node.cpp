#include <iostream>
#include "MyClass.h"
using namespace std;

Node* MPT::findMidNode(){
    if(isEmpty()) return;

    Node* slow = head;
    Node* fast = head;
    while(fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}