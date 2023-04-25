#include <iostream>
using namespace std;

class CircularQueue {
private:
    struct Node {
        int data;
        Node *next;
    };
    Node *rear, *front;

public:
    CircularQueue() {
        rear = nullptr;
        front = nullptr;
    }

    bool isEmpty() {
        if (front == nullptr && rear == nullptr) {
            return true;
        } else {
            return false;
        }
    }

    bool isFull() {
        Node *temp = new Node;
        if (temp == nullptr) {
            return true;
        } else {
            delete temp;
            return false;
        }
    }

    void enqueue(int element) {
        if (isFull()) {
            cout << "Circular Queue is full. Cannot enqueue." << endl;
            return;
        }
        Node *newNode = new Node;
        newNode->data = element;
        newNode->next = nullptr;
        if (isEmpty()) {
            front = newNode;
        } else {
            rear->next = newNode;
        }
        rear = newNode;
        rear->next = front;
        cout << "Enqueued " << element << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Circular Queue is empty. Cannot dequeue." << endl;
            return;
        }
        Node *temp = front;
        int data = temp->data;
        if (front == rear) {
            front = nullptr;
            rear = nullptr;
        } else {
            front = front->next;
            rear->next = front;
        }
        delete temp;
        cout << "Dequeued " << data << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "Circular Queue is empty." << endl;
            return;
        }
        Node *temp = front;
        cout << "Circular Queue elements are: ";
        while (temp->next != front) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << temp->data << endl;
    }
};

int main() {
    CircularQueue cq;
    cq.enqueue(1);
    cq.enqueue(2);
    cq.enqueue(3);
    cq.enqueue(4);
    cq.enqueue(5);

    cq.enqueue(6); // Enqueued 6
    cq.display(); // Circular Queue elements are: 1 2 3 4 5 6

    cq.dequeue();
    cq.dequeue();
    cq.display(); // Circular Queue elements are: 3 4 5 6

    cq.enqueue(6);
    cq.enqueue(7);
    cq.display(); // Circular Queue elements are: 3 4 5 6 7

    cq.enqueue(8); // Circular Queue is full. Cannot enqueue.
    return 0;
}
