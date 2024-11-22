#include<iostream>
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

bool isValid(string s){
    stack st;
    bool ans=true;
    for(int i=0;i<s.length();i++){
        if(s[i]=='{' || s[i]=='(' || s[i]=='['){
            st.push(s[i]);
        }
        else if(!st.isEmpty() && s[i]==')'){
            if(st.Top()=='('){
                st.pop();
            }
            else{
                ans =false;
                break;
            }
        }
        else if(!st.isEmpty() &&s[i]=='}'){
            if(st.Top()=='{'){
                st.pop();
            }
            else{
                ans =false;
                break;
            }
        }
        else if(!st.isEmpty() &&s[i]==']'){
            if(st.Top()=='['){
                st.pop();
            }
            else{
                ans =false;
                break;
            }
        }
    }
    if(!st.isEmpty()){
        ans =false;
    }
    return ans;
}

int main(){
string s="{[(])}";
if(isValid(s)){
    cout<<"Balanced parenthesis."<<endl;
}
else{
    cout<<"Unbalanced."<<endl;
}

return 0;

}