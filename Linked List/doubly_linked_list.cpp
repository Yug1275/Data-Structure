#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = NULL;
        next = NULL;
    }
};

class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() {
        head = NULL;
    }

    // Insert at the front
    void insertAtFront(int val) {
        Node* n = new Node(val);
        if (head != NULL) {
            n->next = head;
            head->prev = n;
        }
        head = n;
    }

    // Insert at the tail
    void insertAtTail(int val) {
        Node* n = new Node(val);
        if (head == NULL) {
            head = n;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = n;
        n->prev = temp;
    }

    // Insert after a given node
    void insertAfterGivenNode(int afterVal, int val) {
        Node* temp = head;
        while (temp != NULL && temp->data != afterVal) {
            temp = temp->next;
        }
        if (temp == NULL) {
            cout << "The item with value " << afterVal << " is not found." << endl;
            return;
        }
        Node* n = new Node(val);
        n->next = temp->next;
        n->prev = temp;
        if (temp->next != NULL) {
            temp->next->prev = n;
        }
        temp->next = n;
    }

    // Delete from the front
    void deleteFront() {
        if (head == NULL) {
            cout << "The list is empty. No element to delete." << endl;
            return;
        }
        Node* toDelete = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        delete toDelete;
    }

    // Delete from the end
    void deleteFromEnd() {
        if (head == NULL) {
            cout << "The list is empty. No element to delete." << endl;
            return;
        }
        if (head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->prev->next = NULL;
        delete temp;
    }

    // Delete by value
    void deleteByValue(int val) {
        if (head == NULL) {
            cout << "The list is empty. No element to delete." << endl;
            return;
        }
        Node* temp = head;
        while (temp != NULL && temp->data != val) {
            temp = temp->next;
        }
        if (temp == NULL) {
            cout << "The item with value " << val << " is not found." << endl;
            return;
        }
        if (temp->prev != NULL) {
            temp->prev->next = temp->next;
        } else {
            head = temp->next; // Deleting the head
        }
        if (temp->next != NULL) {
            temp->next->prev = temp->prev;
        }
        delete temp;
    }

    // Display the list
    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    DoublyLinkedList dll;

    dll.insertAtTail(1);
    dll.insertAtTail(2);
    dll.insertAtTail(3);

    dll.insertAtFront(5);
    dll.insertAtFront(6);

    dll.insertAfterGivenNode(5, 8);
    dll.display();

    dll.deleteFront();
    dll.deleteFromEnd();
    dll.display();

    dll.deleteByValue(5);
    dll.display();

    return 0;
}
