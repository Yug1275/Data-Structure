#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;

    node(int val){
        data=val;
        left=right=NULL;
    }
};

void preorder(node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(node* root){
    if(root==NULL){
        return;
    }
     inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void postorder(node* root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
     cout<<root->data<<" ";
}

int main(){
node* root=new node(1);
root->left=new node(2);
root->right=new node(3);
root->left->left=new node(4);
root->left->right=new node(5);

preorder(root);
cout<<endl;
inorder(root);
cout<<endl;
postorder(root);
    return 0;
}