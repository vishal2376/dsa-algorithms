#include <iostream>
#include <queue>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int data) {
    Node* node = new Node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void inorderTraversal(Node* root) {
    if (root == NULL)
        return;
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

void preorderTraversal(Node* root) {
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(Node* root) {
    if (root == NULL)
        return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}

void levelOrderTraversal(Node* root) {
    if (root == NULL)
        return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* node = q.front();
        q.pop();
        cout << node->data << " ";

        if (node->left != NULL)
            q.push(node->left);
        if (node->right != NULL)
            q.push(node->right);
    }
}

void insert(Node* &root, int data) {
    if (root == NULL) {
        root = newNode(data);
        return;
    }
    if (data < root->data)
        insert(root->left, data);
    else
        insert(root->right, data);
}

int main() {
    Node* root = NULL;
    insert(root, 5);
    insert(root, 3);
    insert(root, 7);
    insert(root, 1);
    insert(root, 4);
    insert(root, 6);
    insert(root, 8);
    cout << "Inorder traversal of binary tree: ";
    inorderTraversal(root);
    cout << endl;
    cout << "Preorder traversal of binary tree: ";
    preorderTraversal(root);
    cout << endl;
    cout << "Postorder traversal of binary tree: ";
    postorderTraversal(root);
    cout << endl;
    cout << "Level Order traversal of binary tree: ";
    levelOrderTraversal(root);
    return 0;
}
