#include <iostream>

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
	return 0;
}