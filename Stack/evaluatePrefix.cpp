#include<iostream>
#include<cmath>
using namespace std;
#define size 20

class stack{
    public:
    int arr[size];
    int top=-1;

    bool isFull(){
        return (top==size-1);
    }

    bool isEmpty(){
        return (top==-1);
    }
    
    void push(int x){
        if(isFull()){
            cout<<"The stack is overflow."<<endl;
        }
        else{
            top++;
            arr[top]=x;
            cout<<x<<" inserted."<<endl;
        }
    }

     void pop(){
        if(isEmpty()){
            cout<<"The stack is underflow."<<endl;
        }
        else{
            cout<<arr[top--]<<" deleted."<<endl;
        }
    }
    int Top(){
        return arr[top];
    }
};

int evaluatePrefix(string prefix){
    stack s;
    for(int i=prefix.length()-1;i>=0;i--){
        char c=prefix[i];

        if(isdigit(c)){
            s.push(c-'0');
        }
        else{
            int operand1=s.Top();
            s.pop();
            int operand2=s.Top();
            s.pop();


            switch(c){
                case '+': s.push(operand1+operand2);
                break;
                case '-': s.push(operand1-operand2);
	            break;
                case '*': s.push(operand1*operand2);
            	break;
                case '/': s.push(operand1/operand2);
	            break;
                }        
    }
}
return s.Top();
}

int main()
{
    string prefix;
cout<<"Enter the prefix expression:(in single word)";
cin>>prefix;
int result=evaluatePrefix(prefix);
cout<<"The output is: "<<result;
}