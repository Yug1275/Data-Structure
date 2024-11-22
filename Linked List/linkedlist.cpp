#include<iostream>
using namespace std;

class node{
public:
	int data;
	node* next;

	node(int value){
	data=value;
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
void insertAfterGiveenNode(int afterVal,int val){
	node* temp=head;
	while(temp!=NULL && temp->data!=afterVal){
		temp=temp->next;
	}

	if(temp==NULL){
		cout<<"The element with value "<<afterVal<<" not found."<<endl;
		return;
	}

	node* n=new node(val);
	n->next=temp->next;
	temp->next=n;
}

void display(){
node* temp=head;
while(temp!=NULL){
	
	cout<<temp->data<<" ->";
	temp=temp->next;
}
 cout<<"NULL"<<endl;
}

void deletion(int val){
	node* temp=head;
	while(temp->next->data!=val){
		temp=temp->next;
	}
	node* todelete=temp->next;
	temp->next=temp->next->next;

	delete todelete;
}

void deleteAtFront(){
	node* todelete=head;
	head=head->next;

	delete todelete;
}
};
int main(){

linkedlist l;
l.insertAtTail(1);
l.insertAtTail(2);
l.insertAtTail(3);

l.insertAtFront(6);
l.insertAtFront(5);

l.insertAfterGiveenNode(5,8);
l.display();

l.deletion(6);
l.deleteAtFront();

l.display();
}