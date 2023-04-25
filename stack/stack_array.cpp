#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

class Stack {
private:
    int arr[MAX_SIZE];
    int top;
public:
    Stack() {
        top = -1;
    }

    bool push(int value) {
        if (top == MAX_SIZE - 1) {
            cout << "Error: Stack overflow" << endl;
            return false;
        }
        top++;
        arr[top] = value;
        return true;
    }

    int pop() {
        if (top == -1) {
            cout << "Error: Stack underflow" << endl;
            return -1;
        }
        int value = arr[top];
        top--;
        return value;
    }

    bool isEmpty() {
        return top == -1;
    }

    int peek() {
        if (top == -1) {
            cout << "Error: Stack is empty" << endl;
            return -1;
        }
        return arr[top];
    }

    void display() {
        if (top == -1) {
            cout << "Stack is empty" << endl;
            return;
        }
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack myStack;
    myStack.push(5);
    myStack.push(10);
    myStack.push(15);
    myStack.push(20);
    myStack.display();
    cout << "Top element: " << myStack.peek() << endl;
    cout << "Popped element: " << myStack.pop() << endl;
    myStack.display();
    cout << "Is stack empty? " << (myStack.isEmpty() ? "Yes" : "No") << endl;
    return 0;
}
