#include <iostream>
using namespace std;

// Define the Node class for the AVL Tree
class Node {
public:
    int val;        // Node value
    Node *left;     // Pointer to the left child
    Node *right;    // Pointer to the right child
    int height;     // Height of the node in the AVL Tree

    // Constructor to create a new Node with a given value
    Node(int val) {
        this->val = val;
        left = NULL;
        right = NULL;
        height = 1;
    }
};

// Define the AVLTree class
class AVLTree {
public:
    Node *root;     // Pointer to the root Node of the AVL Tree

    // Constructor to initialize the AVLTree with a NULL root Node
    AVLTree() {
        root = NULL;
    }

    // Function to get the height of a Node in the AVL Tree
    int height(Node *node) {
        if (node == NULL) {
            return 0;
        }
        return node->height;
    }

    // Function to get the balance factor of a Node in the AVL Tree
    int balance_factor(Node *node) {
        if (node == NULL) {
            return 0;
        }
        return height(node->left) - height(node->right);
    }

    // Function to perform a left rotation on a Node in the AVL Tree
//anticlockwise rotation
    Node *rotate_left(Node *node) {
        Node *new_root = node->right;
        node->right = new_root->left;
        new_root->left = node;

        node->height = max(height(node->left), height(node->right)) + 1;
        new_root->height = max(height(new_root->left), height(new_root->right)) + 1;

        return new_root;
    }

    // Function to perform a right rotation on a Node in the AVL Tree
//clockwise rotation
    Node *rotate_right(Node *node) {
        Node *new_root = node->left;
        node->left = new_root->right;
        new_root->right = node;

        node->height = max(height(node->left), height(node->right)) + 1;
        new_root->height = max(height(new_root->left), height(new_root->right)) + 1;

        return new_root;
    }

    // Function to insert a Node with a given value into the AVL Tree
    Node *insert(Node *node, int val) {
        // If the node is NULL, create a new Node with the given value
        if (node == NULL) {
            return new Node(val);
        }

        // If the value is less than the value of the current node, insert it into the left subtree
        if (val < node->val) {
            node->left = insert(node->left, val);
        } else {    // Otherwise, insert it into the right subtree
            node->right = insert(node->right, val);
        }

        // Update the height of the current node
        node->height = max(height(node->left), height(node->right)) + 1;

        // Get the balance factor of the current node
        int bf = balance_factor(node);

        // Perform the appropriate rotation based on the balance factor and the value of the new Node
        if (bf > 1 && val < node->left->val) {
//RR rotation
            return rotate_right(node);
        }

        if (bf < -1 && val > node->right->val) {
//LL rotation
            return rotate_left(node);
        }


        if (bf > 1 && val > node->left->val) {
//LR rotation
            node->left = rotate_left(node->left);
            return rotate_right(node);
        }

        if (bf < -1 && val < node->right->val) {
//RL rotation
            node->right = rotate_right(node->right);
            return rotate_left(node);
        }

        return node;
    }

    void inorder_traversal(Node *node) {
        if (node == NULL) {
            return;
        }

        inorder_traversal(node->left);
        cout << node->val << " ";
        inorder_traversal(node->right);
    }

    void insert(int val) {
        root = insert(root, val);
    }

    void display() {
        inorder_traversal(root);
    }
};

int main() {
    AVLTree avl;

    avl.insert(10);
    avl.insert(20);
    avl.insert(30);
    avl.insert(40);
    avl.insert(50);
    avl.insert(25);

    avl.display();
    return 0;
}
