#include <iostream>
#include "MyClass.h"
using namespace std;


Node* MPT::rotateList(int p){
    if(isEmpty() || p <=0){
        return;
    }

    // find the length of the list (Circular)
    tail = head;
    while(tail->next){
        tail = tail->next;
    }
    // connect tail and head to each other
    tail->next = head;
    head->prev = tail;

    // moves tail and head upto range p
    while(p){
        head = head->next;
        tail = tail->next;
    }

    // break circular link
    head->next = NULL;
    tail->prev = NULL;

    return head;

}