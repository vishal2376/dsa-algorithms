#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

class Queue {
private:
    int arr[MAX_SIZE];
    int front, rear;
public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool enqueue(int value) {
        if (rear == MAX_SIZE - 1) {
            cout << "Error: Queue overflow" << endl;
            return false;
        }
        if (front == -1) {
            front++;
        }
        rear++;
        arr[rear] = value;
        return true;
    }

    int dequeue() {
        if (front == -1 || front > rear) {
            cout << "Error: Queue underflow" << endl;
            return -1;
        }
        int value = arr[front];
        front++;
        return value;
    }

    bool isEmpty() {
        return front == -1 || front > rear;
    }

    int peek() {
        if (front == -1 || front > rear) {
            cout << "Error: Queue is empty" << endl;
            return -1;
        }
        return arr[front];
    }

    void display() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty" << endl;
            return;
        }
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue myQueue;
    myQueue.enqueue(5);
    myQueue.enqueue(10);
    myQueue.enqueue(15);
    myQueue.enqueue(20);
    myQueue.display();
    cout << "Front element: " << myQueue.peek() << endl;
    cout << "Dequeued element: " << myQueue.dequeue() << endl;
    myQueue.display();
    cout << "Is queue empty? " << (myQueue.isEmpty() ? "Yes" : "No") << endl;
    return 0;
}
