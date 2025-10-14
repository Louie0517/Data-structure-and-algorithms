#include <iostream>
#include "MyClass.h"

using namespace std;

void MPT::swapNode(int s, int e){
    // empty list
    if(isEmpty()) return;

    /* if s and e is equal, return it 
    since there is no need to return
    */
    if(s == e) return;

    /* create START, END pointers equals to NULL
     and CUR pointer to use for traversing to find nodes*/

     Node* start = NULL;
     Node* end = NULL;
     Node* cur = head;

     while(cur){
        // if first value is equal to first node
        if(cur->x == s)
            start = cur;

        // if second node's value is equals to current's value 
        else if(cur->x == e)
            end = cur;

        // if there is no need to swap
        if(start && end) break;

        cur = cur->next;
     }

     // if not there is no existing node "NOT FOUND"
     if(!start || !end){
        cout << "Not Found." << endl;
        return;
     }

     // if nodes are adjacent (HANDLE SEPERATELY)
     if(start->next == end){
        Node* before = start->prev;
        Node* after = end->next;

        if(before)
            before->next = end;
        else 
            head = end;

        if(after)
            after->prev = start;

        /*
        swap the node from start's previous and next 
        to end's previous and next
        */
        end->prev = before;
        end->next = start;
        start->prev = after;
        start->next = end;

        return;
     }

     if(end->next == start){
        // Recursively swap roles to reuse adjacent logic
        swapNode(e, s);
        return;
     }


     // Swap non-adjacent nodes
     Node* startPrev = start->prev;
     Node* startNext = start->next;
     Node* endPrev = end->prev;
     Node* endNext = end->next;

    if(startPrev)
        startPrev->next = end;
    else
        head = end;

    if(startNext)
        startNext->prev = end;

    if(endPrev)
        endPrev->next = start;
    else
        head = start;
    
    if(endNext)
        endNext->prev = start;

    // Swapp Pointers
    start->prev = endPrev;
    start->next = endNext;
    end->prev = startPrev;
    end->next = startNext;

}
