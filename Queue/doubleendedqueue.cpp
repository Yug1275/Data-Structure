#include <iostream>
using namespace std;
#define size 5

int front = -1;
int rear = -1;

struct queue {
    int Q[size];

    // Check if the deque is full
    bool isFull() {
        return ((rear + 1) % size == front);
    }

    // Check if the deque is empty
    bool isEmpty() {
        return (front == -1);
    }

    // Enqueue from the rear
    void enqueueRear(int x) {
        if (isFull()) {
            cout << "Queue overflow." << endl;
        } else if (isEmpty()) {
            front = 0;
            rear = 0;
            Q[rear] = x;
            cout << x << " inserted at rear." << endl;
        } else {
            rear = (rear + 1) % size;
            Q[rear] = x;
            cout << x << " inserted at rear." << endl;
        }
    }

    // Enqueue from the front
    void enqueueFront(int x) {
        if (isFull()) {
            cout << "Queue overflow." << endl;
        } else if (isEmpty()) {
            front = 0;
            rear = 0;
            Q[front] = x;
            cout << x << " inserted at front." << endl;
        } else {
            front = (front - 1 + size) % size;
            Q[front] = x;
            cout << x << " inserted at front." << endl;
        }
    }

    // Dequeue from the front
    void dequeueFront() {
        if (isEmpty()) {
            cout << "Queue underflow." << endl;
        } else if (front == rear) {
            int temp = Q[front];
            front = rear = -1;
            cout << temp << " removed from front." << endl;
        } else {
            int temp = Q[front];
            front = (front + 1) % size;
            cout << temp << " removed from front." << endl;
        }
    }

    // Dequeue from the rear
    void dequeueRear() {
        if (isEmpty()) {
            cout << "Queue underflow." << endl;
        } else if (front == rear) {
            int temp = Q[rear];
            front = rear = -1;
            cout << temp << " removed from rear." << endl;
        } else {
            int temp = Q[rear];
            rear = (rear - 1 + size) % size;
            cout << temp << " removed from rear." << endl;
        }
    }

    // Display the elements in the deque
    void peek() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
        } else {
           cout << "Queue elements: ";
for (int i = front; ; i = (i +1) % size) {
    cout << Q[i] << " ";
    if (i == rear) break;
}

            cout << endl;
        }
    }

    // Display the front element
    void Front() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
        } else {
            cout << "Front -> " << Q[front] << endl;
        }
    }

    // Display the rear element
    void Rear() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
        } else {
            cout << "Rear -> " << Q[rear] << endl;
        }
    }
};

int main() {
    struct queue q;

    // Test operations
    q.enqueueRear(1);
    q.enqueueRear(2);
    q.enqueueRear(3);
    q.enqueueFront(0);
    q.enqueueRear(4);

    q.peek();

    q.dequeueFront();
    q.dequeueRear();

    q.peek();

    q.enqueueFront(-1);
    q.enqueueRear(5);

    q.peek();

    q.Front();
    q.Rear();

    return 0;
}
