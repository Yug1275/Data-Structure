#include<iostream>
using namespace std;

class node{
public:
int data;
node* next;
public:
node(int val){
    data=val;
    next=NULL;  
}
};

class linkedlist{
    
    private:
    node* head;
    public:
    linkedlist(){
        head=NULL;
    }

    void insertAtFront(int val){
        node* n=new node(val);

        n->next=head;
        head=n;
    }

    void insertAfterGivenNode(int afterVal,int val){
        node* temp=head;
        while(temp!=NULL && temp->data!=afterVal){
            temp=temp->next;
        }
        if(temp==NULL){
            cout<<"The item with value "<<afterVal<<" is not found."<<endl;
            return;
        }
        node* n=new node(val);
        n->next=temp->next;
        temp->next=n;
    }
    void insertAtTail(int val){
        node* n=new node(val);

        if(head==NULL){
            head=n;
            return;
        }
        node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=n;
    }

    void deletefront(){
        node* todelete=head;
        head=head->next;
        delete todelete;
    }
    void deleteFromEnd() {
        if (head == NULL) {
            cout << "The list is empty. No element to delete." << endl;
            return;
        }
        if (head->next == NULL) {
            // If there's only one node
            delete head;
            head = NULL;
            return;
        }
        node* temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        node* todelete = temp->next;
        temp->next = NULL;
        delete todelete;
    }
    
    void deletion(int val){
        node* todelete=new node(val);
        node* temp=head;
        while(temp->next->data!=val){
            temp=temp->next;
        }
        if(temp->next==NULL){
            cout<<"Not found."<<endl;
            return;
        }

        temp->next=temp->next->next;

        delete todelete;
    }

    void display(){
        node* temp=head;

        while(temp!=NULL){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;

    }
};
int main(){
linkedlist l;

l.insertAtTail(1);
l.insertAtTail(2);
l.insertAtTail(3);
l.insertAtFront(5);
l.insertAtFront(6);
l.insertAfterGivenNode(5,8);
l.display();
l.deletefront();
l.deleteFromEnd();
l.display();


    return 0;
}