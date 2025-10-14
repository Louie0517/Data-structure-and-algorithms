#include <iostream>
#include "MyClass.h"

using namespace std;
// sorted doubly linked list
void MPT::removeDuplicateNodes(){
    if(isEmpty()){
        cout << "Empty List." << endl;
        return;
    }

    Node* temp = head;
    while(temp != NULL && temp->next != NULL){
        // store second node
        Node* nextNode = temp->next;

        // traverse until its NULL and second node's value is equal to first node's value
        while(nextNode != NULL && nextNode->x == temp->x){
            nextNode = nextNode->next;
        }

        temp->next = nextNode;
        if(nextNode != NULL) nextNode->prev = temp;
        temp = temp->next;
    }

    /*
        Print temp->x if you want to display the remaining values,
        after removing duplicates.
    */

}