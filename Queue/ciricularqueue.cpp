#include<iostream>
using namespace std;
#define size 5

int front=-1;
int rear=-1;

struct queue{
	int Q[size];

	bool isFull(){
	return ((rear+1)%size==front);
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
	rear=(rear+1)%size;
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
	front=(front+1)%size;
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
	q.dequeue();
	q.dequeue();

	q.peek();
	q.enqueue(6);
	q.enqueue(7);
	q.enqueue(8);
	q.enqueue(9);

	q.dequeue();
	q.dequeue();
	q.dequeue();
	q.dequeue();

	q.Front();
	q.Rear();
}


