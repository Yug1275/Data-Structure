#include<iostream>
using namespace std;
#define size 5

int front=-1;
int rear=-1;

struct queue{
	int Q[size];

	bool isFull(){
	return (rear>=size-1);
	}

	bool isEmpty(){
	return (front==-1);
	}

	void enqueue(int x){
	if(isFull()){
	cout<<"Queue overflow.";
	}

	else if(isEmpty()){
	front=0;
	rear=0;
	Q[rear]=x;
	cout<<x<<" inserted."<<endl;
	}
	
	else{		
	rear++;
	Q[rear]=x;
	cout<<x<<" inserted."<<endl;
	}	
	}

	void dequeue(){
	if(isEmpty()){
	cout<<"Queue underflow.";
	}

	else if(front==rear){
	int temp=Q[front];
	front=rear=-1;
	cout<<temp<<" removed."<<endl;
	}
	
	else{	
	int temp=Q[front];	
	front++;
	cout<<temp<<" removed."<<endl;
	}
	}

	void peek(){
		for(int i=front;i<=rear;i++){
				cout<<Q[i]<<" ";
		}
		cout<<endl;
	}

	void Front(){
	cout<<"front ->"<<Q[front]<<endl;
	}

	void Rear(){
	cout<<"rear ->"<<Q[rear];
	}

	

	
};

int main(){
struct queue q;
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	q.enqueue(5);
	
 
	q.dequeue();
	q.dequeue();

	q.peek();

	q.Front();
	q.Rear();
}


