#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;

    node(int val) {
        data = val;
        next = NULL;
    }
};

class circularLinkedList {
private:
    node* head;

public:
    circularLinkedList() {
        head = NULL;
    }

    // Insert at the front
    void insertAtFront(int val) {
        node* n = new node(val);
        if (head == NULL) {
            head = n;
            n->next = head; // Point to itself to form a circle
        } else {
            node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            n->next = head;
            temp->next = n;
            head = n;
        }
    }

    // Insert at the end (tail)
    void insertAtTail(int val) {
        node* n = new node(val);
        if (head == NULL) {
            head = n;
            n->next = head; // Point to itself to form a circle
        } else {
            node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = n;
            n->next = head;
        }
    }

    // Insert after a given node value
    void insertAfterGivenNode(int afterVal, int val) {
        if (head == NULL) {
            cout << "List is empty. Cannot insert." << endl;
            return;
        }
        node* temp = head;
        do {
            if (temp->data == afterVal) {
                node* n = new node(val);
                n->next = temp->next;
                temp->next = n;
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "The item with value " << afterVal << " is not found." << endl;
    }

    // Delete from the front
    void deleteFront() {
        if (head == NULL) {
            cout << "The list is empty. No element to delete." << endl;
            return;
        }
        if (head->next == head) {
            delete head;
            head = NULL;
            return;
        }
        node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        node* toDelete = head;
        temp->next = head->next;
        head = head->next;
        delete toDelete;
    }

    // Delete from the end
    void deleteFromEnd() {
        if (head == NULL) {
            cout << "The list is empty. No element to delete." << endl;
            return;
        }
        if (head->next == head) {
            delete head;
            head = NULL;
            return;
        }
        node* temp = head;
        while (temp->next->next != head) {
            temp = temp->next;
        }
        node* toDelete = temp->next;
        temp->next = head;
        delete toDelete;
    }

    // Delete a node by value
    void deletion(int val) {
        if (head == NULL) {
            cout << "The list is empty. No element to delete." << endl;
            return;
        }
        if (head->data == val) {
            deleteFront();
            return;
        }
        node* temp = head;
        do {
            if (temp->next->data == val) {
                node* toDelete = temp->next;
                temp->next = temp->next->next;
                delete toDelete;
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "The item with value " << val << " is not found." << endl;
    }

    // Display the circular linked list
    void display() {
        if (head == NULL) {
            cout << "The list is empty." << endl;
            return;
        }
        node* temp = head;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(back to head)" << endl;
    }
};

int main() {
    circularLinkedList cl;

    // Insert elements
    cl.insertAtTail(1);
    cl.insertAtTail(2);
    cl.insertAtTail(3);
    cl.insertAtFront(5);
    cl.insertAtFront(6);
    cl.insertAfterGivenNode(5, 8);

    // Display list
    cl.display();

    // Delete from front
    cl.deleteFront();

    // Delete a node by value
    cl.deletion(9);  // Value not found
    cl.deletion(8);  // Delete 8

    // Display list again
    cl.display();

    // Delete from end
    cl.deleteFromEnd();
    cl.insertAtFront(7);
    cl.display();

    return 0;
}
