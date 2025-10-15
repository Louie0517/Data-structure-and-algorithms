#include <iostream>
#include "MyClass.h"
using namespace std;

void MPT::printList(){
    Node* cur = head;

    while(cur){
        cout << cur->x;
        if(cur->next)
            cout << "<->";
        cur = cur->next;
    }
}


int main(){

    MPT mp;

    
    // mp.setHead(new Node(10));
    // mp.getHead()->next = new Node(20);
    // mp.getHead()->next->next = new Node(30);
    // mp.getHead()->next->next->next = new Node(40);
    // mp.getHead()->next->next->next->next = new Node(50);
    // mp.getHead()->next->next->next->next->next = new Node(60);
    // mp.getHead()->next->next->next->next->next->next = new Node(70);

    // mp.swapNode(2, 3);
    // mp.printList();
    
    return 0;
}