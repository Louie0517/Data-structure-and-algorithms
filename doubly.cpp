#include <iostream>

using namespace std;

struct Node{
    int x;
    Node* next;
    Node* prev;
    Node(int val):x(val), next(NULL), prev(NULL){}
    Node():x(), next(NULL), prev(NULL){}
};

class MPT{
    private:
    Node* head;
    Node* tail;
    public:
    MPT():head(NULL), tail(NULL){}

    void insertAtHead(int x);
    void insertedAtTail(int x);
    void insertAtIndex(int i, int x);
    void deleteAtHead();
    void deleteAtTail();
    void deleteAtIndex(int i);
    void searchByVal(int x);
    void traversalAndPrint();
    void reverseTraversalAndPrint();
    int countOccurence(int t);
    Node* reverseSub(int m, int n);
    void clearList();
    void reverse();
    int getSize();
    bool isEmpty();
    void swapNode(int s, int e);
};

int tr = 0;
bool MPT::isEmpty(){
    return head = tail = NULL;
}
void MPT::insertAtHead(int x){
    Node* newNode = new Node(x);
    newNode->prev = NULL;
    if(head != NULL){
        newNode->next = head;
    }
    head = newNode;
    cout << "ADDED." << endl;
}

void MPT::insertedAtTail(int x){
    Node* newNode = new Node(x);
    newNode->next = NULL;

    if(tail != NULL){
        newNode->prev = tail;
    }
    tail = newNode;
    cout << "ADDED." << endl;
}

void MPT::insertAtIndex(int i, int x){
    Node* newNode = new Node(x);
    
    if(i == 0){
        newNode->next = head;
        head = newNode;
        cout << "ADDED." << endl;
    }
    Node* cur = head;
    while(cur != NULL && tr < i){
        tr++;
        cur = cur->next;
    }

    if(!cur) {
        cout << "NONE." << endl;
        return;
    }
    else{
        newNode->next = cur->next;
        newNode->prev = cur;
        cur->next = newNode;
        cout << "ADDED." << endl;
    }
}


void MPT::deleteAtHead(){
    if(isEmpty()){
        cout << "EMPTY." << endl;
        return;
    } 

    Node* temp = head;
    head = head->next;
    delete temp;
    cout << "DELETED." << endl;

}

void MPT::deleteAtTail(){
    if(isEmpty()){
        cout << "EMPTY." << endl;
        return;
    }

    Node* temp = tail;
    tail = tail->prev;
    delete temp;
    cout << "DELETED." << endl;
}

void MPT::deleteAtIndex(int i){
    if(isEmpty()){
        cout << "EMPTY." << endl;
        return;
    }
    Node* ptr = head;
    while(ptr != NULL && tr < i){
        tr++;
        ptr = ptr->next;
    }

    if(!ptr) cout << "NONE." << endl;
    if(ptr == head && ptr == tail){
        head = tail = NULL;
    }

    else if(ptr == head){
        head = head->next;
        head->prev = NULL;
    }
    else if(ptr == tail){
        tail = tail->prev;
        tail->next = NULL;
    } else {
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
    }
    cout << "DELETED." << endl;

}


void MPT::searchByVal(int x){
    if(isEmpty()){
        cout << "EMPTY." << endl;
        return;
    }

    Node* cur = head;
    while(cur != NULL && cur->x != x) {
        tr++;
        cur = cur->next;
    }

    if(!cur) cout << "NONE." << endl;
    else{
        cout << cur->x << "FOUND: " << tr << endl;
    }

}

void MPT::traversalAndPrint(){
    if(isEmpty()){
        cout << "EMPTY." << endl;
        return;
    }

    Node* cur = head;
    while(cur != NULL){
        cout << cur->x << " ";
        cur = cur->next;
    }
    cout << endl;


}

void MPT::reverseTraversalAndPrint(){
    if(isEmpty()){
        cout << "EMPTY" << endl;
        return;
    }

    Node* cur = tail;
    while(cur != NULL){
        cout << cur->x << " ";
        cur = cur->next;
    }

    cout << endl;

}

int MPT::getSize(){
    if(isEmpty()){
        cout << "EMPTY." << endl;
        return;
    }

    Node* ptr = head;
    while(ptr != NULL){
        tr++; 
        ptr = ptr->next;
    }

    return tr;
}

void MPT::clearList(){
    Node* temp = head;
    Node* newNode = new Node();
    while(temp != NULL){
        newNode = temp;
        temp = temp->next;
    }
    delete newNode;
}

int MPT::countOccurence(int t){
    if(isEmpty()){
        cout << "EMPTY." << endl;
        return;
    }

    Node* ptr = head;
    while(ptr != NULL){
        if(ptr->x == t)tr++;
        ptr = ptr->next;
    }

return tr;
}

void MPT::reverse(){
    if(isEmpty()){
        cout << "EMPTY." << endl;
        return;
    }

    Node* ptr = head;
    Node* t = new Node();
    while(ptr != NULL && ptr->next != NULL){
        if(ptr->x > ptr->next->x){
            t->x = ptr->next->x;
            ptr->next->x = ptr->x;
            ptr->x = t->x;
        }
        cout << "REVERSED: " <<  ptr->x << endl;
        ptr = ptr->next;
    }
}

Node* revs(Node* head){
    Node* cur = head;
    Node* prev = NULL;

    while(cur){
        Node* nxtNode = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxtNode;
    }

    return prev;

}

Node* MPT::reverseSub(int start, int end){
    if(isEmpty()){
         cout << "EMPTY." << endl;
        return;
    }

    
    if( start == end) return head;

    Node* rev = NULL;
    Node* revPrev = NULL;
    Node* revEnd = NULL;
    Node* revEndNxt = NULL;

    Node* cur = head;
    while(cur != NULL && tr <= end){
        if(tr < start) revPrev = cur;
        if(tr == start) rev = cur;
        if(tr == end){
            revEnd = cur;
            revEndNxt = cur->next;
        }
        cur = cur->next;
        tr++;

    }
    revEnd->next = NULL;
    revEnd = revs(rev);
    if(revPrev){
        revPrev->next = revEnd;
    }else{
        head = revEnd;
    }
    rev->next = revEndNxt;
    return head;
}


void MPT::swapNode(int s, int e){
    if(isEmpty()){
         cout << "EMPTY." << endl;
        return;
    }

    // if value one and second, return. since there is no need to swap
    if(s == e) return;
    // initialize start and end set equals to NULL
    Node* start = NULL;
    Node* end = NULL;
    // create cur, pointing to head
    Node* cur = head;

    // traverse and find nodes with value first and second
    while(cur){
        /*
            first node value equals to start value,
            start will be cur
        */  
        if(cur->x == s)
            start = cur;
        /*
            second node value equals to end (second node) value,
            end will be cur
        */  
        else if(cur->x == e){
            end = cur;
        }

        /*
            break if nothing to reverse
        */
        if(start && end)
            break;

        // for traversing
        cur = cur->next;
        

        if(!start || !end){
            cout << "One or both not found." << endl;
            return;
        }

        // swap nodes by adjusting pointers
        if(start->prev)
            start->prev->next = end;
        else   
            head = end;
        
        if(end->prev)
            end->prev->next = start;
        else
            head = start;

        start->prev = end->prev;
        end->prev = start->prev;

        if(start->next)
            start->next->prev = end;
        if(end->next)
            end->next->prev = start;

        start->next = end->next;
        end->next = start->next;

    }

}