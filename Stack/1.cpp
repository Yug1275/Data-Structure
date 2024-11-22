#include<stdio.h>
#define size 20

int arr[size];
int top=-1;

int isFull(){
    if(top==size-1){
        return 1;
    }
    else {
        return 0;
    }
}
int isEmpty(){
    if(top==-1){
        return 1;
    }
    else {
        return 0;
    }
}

void push(int value){
    if(isFull()){
        printf("The stack is overflow.");
    }
    else{
        arr[++top]=value;
        printf("%d inserted\n",value);
    }
}

void pop(){
    if(isEmpty()){
        printf("Stack underflow.");
    }
    else{
        printf(" %d deleted\n", arr[top--]);
    }
}

void peek(){
    for(int i=top;i>=0;i--){
        printf("%d ",arr[i]);
    }
}

int main(){

    int arr[size]={2,3,1,};
    // int data;
    // printf("enter data to be pushed: ");
    // scanf("%d",&data);
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    push(6);
    
    pop();
    pop();
    peek();
}