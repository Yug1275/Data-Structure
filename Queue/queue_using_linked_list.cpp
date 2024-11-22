#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int val){
        data=val;
        next=NULL;
    }
};

class queue{
    public:
    node* front;
    node* rear;

    queue(){
        front=rear=NULL;
    }

    bool isEmpty(){
        return (front==NULL);
    }

    void enqueue(int x){
        node* n=new node(x);
        node* temp=front;

        if(front==NULL){
            front=n;
            rear=n;
            return;
        }
       
        rear->next=n;
        rear=n;
    }

    void dequeue(){
        if(front==NULL){
            cout<<"Queue is empty.";
            return;
        }
        node* todelete=front;
        front=front->next;

        delete todelete;
    }

    void display(){
        node* temp=front;

        while(temp!=NULL){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }
};

int main(){
queue q;
q.enqueue(1);
q.enqueue(2);
q.enqueue(3);
q.enqueue(4);
q.dequeue();
q.dequeue();
q.display();
}