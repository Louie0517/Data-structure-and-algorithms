#include <iostream>

using namespace std;

struct Double{
    Double* prev;
    Double* next;
    int data;
};

class ADTList{
private:
    Double* head;
    Double* tail;

public:
    ADTList(): head(NULL), tail(NULL){};
    ~ADTList(){
    Double *p, *n;
    p = head;

    while(p!=NULL){
        Double *n = p;
        p = p->next;
        delete(n);
    }
    head=NULL;
    tail=NULL;
}

    void add(int data);
    void del(int data);
    void upd(int data);
    void disp();

};
int menu();

    void ADTList::add(int data){
        // check if head is empty.
        Double* newNode = new Double;
        newNode->data = data;
        if(!head){
            head = tail =  newNode;
        }

        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        cout << "Added!\n";
        system("pause");
    }

    void ADTList::del(int data){
            Double* cur = head;
        // if head is empty
        if(!head){
            cout << "Node is empty." << endl;
            return;
        }

        while(cur != NULL && cur->data != data){
            cur = cur->next;
        }

        // traverse but not found any
        if(!cur){
            cout << "Not found." << endl;
            system("pause");
        }

        // if only one existing
        if(cur == head && cur == tail){
            head = tail = NULL;
        }

        // if data is equal to head
        else if(cur == head){
            head = head->next;
            head->prev = NULL;
        }

        // if data is equal to tail
        else if(cur == tail){
            tail = tail->prev;
            tail->next = NULL;
        }
        else {
            // removing the middle
            cur->next->prev = cur->prev; // link my next node to my previous current
            cur->prev->next = cur->next; // link my previous node to my next current
        }
        delete cur;
        cout << "Deleted!\n";
    }

    int menu(){
        int c;

        cout << "[1]Insert\n[2]Delete\nSelect[1-2]: ";
        cin >> c;

        return c;
    }

int main(){

        ADTList l;
        Double d;
    while(true){
        switch(menu()){
            case 1:
                cout << "Insert x: "; cin >> d.data;
                l.add(d.data);
                break;
            case 2:
                cout << "Insert x: "; cin >> d.data;
                l.del(d.data);
                break;
            default:
                cout << "Invalid input..\n";
                break;
        };
    }

        return 0;
    }
