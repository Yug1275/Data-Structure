#include<iostream>
#include<cmath>
using namespace std;

#define size 100
struct stack{

	int arr[size];
	int top=-1;

	bool isFull(){
	return (top==size-1);
	}

	bool isEmpty(){
	return (top==-1);
	}

	void push(int x){
	top++;
	arr[top]=x;
	}

	void pop(){
	arr[top--];
	}
	int Top(){
	return arr[top];
	}
};

int evaluatePostfix(string postfix){
 stack s;
for(int i=0;i<postfix.length();i++){
char c=postfix[i];

if(isdigit(c)){
s.push(c-'0');
}
else{
int operand2= s.Top();
s.pop();
int operand1=s.Top();
s.pop();


switch(c){
case '+': s.push(operand1 + operand2);
	break;
case '-': s.push(operand1-operand2);
	break;
case '*': s.push(operand1*operand2);
	break;
case '/': s.push(operand1/operand2);
	break;
case '^': s.push(pow(operand1,operand2));
	break;
}
}
}
return s.Top();
}

int main(){
string postfix;
cout<<"Enter the postfix expression:(in single word)";
cin>>postfix;
int result=evaluatePostfix(postfix);
cout<<"The output is: "<<result;

return 0;
}