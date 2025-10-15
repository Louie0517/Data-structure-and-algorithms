#ifndef MPT_H
#define MPT_H

struct Node{
    int x;
    Node* next;
    Node* prev;
    Node(int val):x(val), next(nullptr), prev(nullptr){}
    Node():x(), next(nullptr), prev(nullptr){}
};

class MPT{
    private:
    Node* head;
    Node* tail;

    public:
    MPT():head(nullptr), tail(nullptr){}
    void swapNode(int s, int e);
    void removeDuplicateNodes();
    void printList();
    bool isEmpty();
    Node* findMidNode();
    Node* rotateList(int p);
    Node* getHead(){
        return head;
    }
    void setHead(Node* setH){ head = setH;}
};

bool MPT::isEmpty(){
    return head = tail = nullptr;
}

#endif