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
node* inorderSucc(node* root){
    node* curr=root;
    while(curr && curr->left!=NULL){
        curr=curr->left;
    }
    return curr;
}

node* deleteinBST(node* root,int key){
    if(key<root->data){
        root->left=deleteinBST(root->left,key);
    }
    else if(key>root->data){
        root->right=deleteinBST(root->right,key);
    }
    else{
        if(root->left==NULL){
            node* temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL){
            node* temp=root->left;
            free(root);
            return temp;
        }
        node* temp=inorderSucc(root->right);
        root->data=temp->data;
        root->right=deleteinBST(root->right,temp->data);
    }
    return root;
}


void inorder(node* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left); // Visit left subtree
    cout << root->data << " "; // Print the root data
    inorder(root->right); // Visit right subtree
}

int main() {
    node* root= new node(4);
    root->left=new node(2);
    root->right=new node(5);
    root->left->left=new node(1);
    root->left->right=new node(3);
    root->right->right=new node(6);
   
    cout << "In-order traversal of the BST: ";
    inorder(root);
    cout << endl;
    root=deleteinBST(root,5);
    inorder(root);
    cout<<endl;


    return 0;
}
