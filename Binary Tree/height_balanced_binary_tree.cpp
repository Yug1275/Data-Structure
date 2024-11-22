#include <iostream>
#include <algorithm>
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

// Function to calculate the height of a binary tree
int height(node* root) {
    if (root == NULL) {
        return 0; // Base case: height of an empty tree is 0
    }
    int lh = height(root->left);  // Height of left subtree
    int rh = height(root->right); // Height of right subtree
    return max(lh, rh) + 1;       // Height of current node
}

// Function to check if a binary tree is balanced
bool isBalanced(node* root) {
    if (root == NULL) {
        return true; // Base case: an empty tree is balanced
    }

    // Check if left and right subtrees are balanced
    if (!isBalanced(root->left)) {
        return false;
    }
    if (!isBalanced(root->right)) {
        return false;
    }

    // Check the height difference
    int lh = height(root->left);
    int rh = height(root->right);
    if (abs(lh - rh) <= 1) {
        return true;
    } else {
        return false;
    }
}

int main() {
    // Constructing a binary tree
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(4);
    root->right->left = new node(6);
    root->right->right = new node(4);

    // Check if the tree is balanced
    if (isBalanced(root)) {
        cout << "Balanced" << endl;
    } else {
        cout << "Unbalanced" << endl;
    }

    return 0;
}
