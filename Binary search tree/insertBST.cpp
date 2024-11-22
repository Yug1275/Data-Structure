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

// Function to insert a value into the BST
node* insertBST(node* root, int val) {
    if (root == NULL) {
        return new node(val); // Create a new node if root is NULL
    }

    if (val < root->data) {
        root->left = insertBST(root->left, val); // Insert into left subtree
    } else {
        root->right = insertBST(root->right, val); // Insert into right subtree
    }

    return root;
}

// Function for in-order traversal of the BST
void inorder(node* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left); // Visit left subtree
    cout << root->data << " "; // Print the root data
    inorder(root->right); // Visit right subtree
}

int main() {
    node* root = NULL;

    // Inserting values into the BST
    root = insertBST(root, 5);
    insertBST(root, 1);
    insertBST(root, 3);
    insertBST(root, 4);
    insertBST(root, 2);
    insertBST(root, 7);

    // Print in-order traversal of the BST
    cout << "In-order traversal of the BST: ";
    inorder(root);
    cout << endl;

    return 0;
}
