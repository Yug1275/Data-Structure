#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class Stack {
public:
    Node* top;

    Stack() {
        top = NULL;
    }

    bool isEmpty() {
        return (top == NULL);
    }

    void push(int x) {
        Node* n = new Node(x);
        n->next = top;
        top = n;
    }

    void pop() {
        if (isEmpty()) {
            cout << "The stack is empty. Nothing to pop." << endl;
            return;
        }
        Node* toDelete = top;
        top = top->next;
        delete toDelete;
    }

    void display() {
        if (isEmpty()) {
            cout << "The stack is empty." << endl;
            return;
        }
        Node* temp = top;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    s.display();

    s.pop();
    cout << "After popping an element:" << endl;
    s.display();

    return 0;
}
