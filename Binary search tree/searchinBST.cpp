#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;

    // Constructor to initialize a new node
    node(int val) {
        data = val;
        left = right = NULL;
    }
};

node* searchinBST(node* root, int key){
    if(root==NULL){
        return NULL;
    }
    if(root->data==key){

        return root;
    }

    if(root->data > key){
        return searchinBST(root->left,key);
    }
    else{
        return searchinBST(root->right,key);
    }
    
}

int main(){
    node* root=new node(4);
    root->left=new node(1);
    root->right=new node(5);
    root->left->left=new node(1);
    root->left->right=new node(3);
    root->right->right=new node(6);

    if(searchinBST(root,10)==NULL){
        cout<<"Not exists.";
    }
    else{
        cout<<"Exists.";
    }
    return 0;
}