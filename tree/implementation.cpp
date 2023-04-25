
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
};

Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node* root, int value) {
    if (root == NULL) {
        root = createNode(value);
        return root;
    }
    else if (value <= root->data) {
        root->left = insertNode(root->left, value);
    }
    else {
        root->right = insertNode(root->right, value);
    }
    return root;
}

bool searchNode(Node* root, int value) {
    if (root == NULL) {
        return false;
    }
    else if (root->data == value) {
        return true;
    }
    else if (value <= root->data) {
        return searchNode(root->left, value);
    }
    else {
        return searchNode(root->right, value);
    }
}

int main() {
    Node* root = NULL;
    root = insertNode(root, 10);
    root = insertNode(root, 7);
    root = insertNode(root, 15);
    root = insertNode(root, 5);
    root = insertNode(root, 11);
    root = insertNode(root, 20);

    if (searchNode(root, 15)) {
        cout << "15 found in tree" << endl;
    }
    else {
        cout << "15 not found in tree" << endl;
    }

    if (searchNode(root, 12)) {
        cout << "12 found in tree" << endl;
    }
    else {
        cout << "12 not found in tree" << endl;
    }

    return 0;
}
