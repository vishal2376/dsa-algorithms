#include <iostream>
using namespace std;

class Stack {
private:
    struct Node {
        int data;
        Node *next;
    };
    Node *top;

public:
    Stack() {
        top = nullptr;
    }

    bool isEmpty() {
        if (top == nullptr) {
            return true;
        } else {
            return false;
        }
    }

    void push(int element) {
        Node *newNode = new Node;
        newNode->data = element;
        newNode->next = top;
        top = newNode;
        cout << "Pushed " << element << endl;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot pop." << endl;
        } else {
            Node *temp = top;
            int data = temp->data;
            top = temp->next;
            delete temp;
            cout << "Popped " << data << endl;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
        } else {
            cout << "Stack elements are: ";
            Node *temp = top;
            while (temp != nullptr) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main() {
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    s.push(6); // Pushed 6
    s.display(); // Stack elements are: 6 5 4 3 2 1

    s.pop();
    s.pop();
    s.display(); // Stack elements are: 4 3 2 1

    s.push(6);
    s.push(7);
    s.display(); // Stack elements are: 7 6 4 3 2 1
    return 0;
}
