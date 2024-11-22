#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;

    node(int value) {
        data = value;
        next = NULL;
    }
};

class linkedlist {
private:
    node* head;

public:
    linkedlist() {
        head = NULL;
    }

    void insertAtTail(int val) {
        node* n = new node(val);

        if (head == NULL) {
            head = n;
            return;
        }
        node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = n;
    }

    void display() {
        node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    node* reverse() {
        node* prevptr = NULL;
        node* currentptr = head;
        node* nextptr;

        while (currentptr != NULL) {
            nextptr = currentptr->next;
            currentptr->next = prevptr;

            prevptr = currentptr;
            currentptr = nextptr;
        }
         head= prevptr; // Update head to point to the new first node
    }
    node* reverserecursive(node* &head){

        if(head==NULL || head->next==NULL){
            return head;
        }
        node* newhead=reverserecursive(head->next);
        head->next->next=head;
        head->next=NULL;
         return newhead;
    }
   
};

int main() {
    linkedlist l;
    l.insertAtTail(1);
    l.insertAtTail(2);
    l.insertAtTail(3);
    l.insertAtTail(4);

    cout << "Original List: ";
    l.display();
    node* newhead=NULL;
    l.reverserecursive(newhead);

    cout << "Reversed List: ";
    l.display();

    return 0;
}
