#include <iostream>
using namespace std;

class CircularQueue {
private:
    int front, rear;
    int capacity;
    int *arr;

public:
    CircularQueue(int size) {
        capacity = size;
        front = -1;
        rear = -1;
        arr = new int[size];
    }

    bool isFull() {
        if ((front == 0 && rear == capacity - 1) || front == rear + 1) {
            return true;
        } else {
            return false;
        }
    }

    bool isEmpty() {
        if (front == -1) {
            return true;
        } else {
            return false;
        }
    }

    void enqueue(int element) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue " << element << endl;
        } else {
            if (front == -1) {
                front = 0;
            }
            rear = (rear + 1) % capacity;
            arr[rear] = element;
            cout << "Enqueued " << element << endl;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
        } else {
            cout << "Dequeued " << arr[front] << endl;
            if (front == rear) {
                front = -1;
                rear = -1;
            } else {
                front = (front + 1) % capacity;
            }
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
        } else {
            cout << "Circular Queue elements are: ";
            int i = front;
            while (i != rear) {
                cout << arr[i] << " ";
                i = (i + 1) % capacity;
            }
            cout << arr[rear] << endl;
        }
    }
};

int main() {
    CircularQueue q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    q.enqueue(6); // Queue is full. Cannot enqueue 6
    q.display(); // Circular Queue elements are: 1 2 3 4 5

    q.dequeue();
    q.dequeue();
    q.display(); // Circular Queue elements are: 3 4 5

    q.enqueue(6);
    q.enqueue(7);
    q.display(); // Circular Queue elements are: 3 4 5 6 7
    return 0;
}
