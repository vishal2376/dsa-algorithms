#include <iostream>
using namespace std;

class Queue {
private:
    struct Node {
        int data;
        Node *next;
    };
    Node *front, *rear;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    bool isEmpty() {
        if (front == nullptr) {
            return true;
        } else {
            return false;
        }
    }

    void enqueue(int element) {
        Node *newNode = new Node;
        newNode->data = element;
        newNode->next = nullptr;
        if (isEmpty()) {
            front = newNode;
        } else {
            rear->next = newNode;
        }
        rear = newNode;
        cout << "Enqueued " << element << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
        } else {
            Node *temp = front;
            int data = temp->data;
            front = front->next;
            delete temp;
            cout << "Dequeued " << data << endl;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
        } else {
            cout << "Queue elements are: ";
            Node *temp = front;
            while (temp != nullptr) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main() {
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    q.enqueue(6); // Enqueued 6
    q.display(); // Queue elements are: 1 2 3 4 5 6

    q.dequeue();
    q.dequeue();
    q.display(); // Queue elements are: 3 4 5 6

    q.enqueue(6);
    q.enqueue(7);
    q.display(); // Queue elements are: 3 4 5 6 7
    return 0;
}
