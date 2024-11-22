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

string reverseString(string s){
    stack st;
    for (int i = 0; i < s.length(); i++)
    {
        char c=s[i];
        st.push(c);
    }
    string reversed="";
    while(!st.isEmpty()){
        reversed+=st.Top();
        st.pop();
    }
    for (int i = 0; i < reversed.length(); i++) {
        if (reversed[i] == '(') {
            reversed[i] = ')';
        } else if (reversed[i] == ')') {
            reversed[i] = '(';
        }
    }
    

    return reversed;
    
}

int main(){
    string original="(a-b/c)*(a/k-l)";
     

    cout<<reverseString(original);
}