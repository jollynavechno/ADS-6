// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

template <typename T>
class BST {
 public:
struct Node {
T data;
int count;
Node* left;
Node* right;
};
BST() :root(nullptr) {}
~BST() {};
void add(T data) {
root = addNode(root, data);
}
int depth() {
return depthTree(root) - 1;
}
int search(T data) {
return countNodes(root, data);
}

 private:
Node* root;
Node* addNode(Node* root, T data) {
if (root == nullptr) {
root = new Node;
root->data = data;
root->count = 1;
root->left = root->right = nullptr;
} else if (root->data > data) {
root->left = addNode(root->left, data);
} else if (root->data < data) {
root->right = addNode(root->right, data);
} else {
root->count++;
}
return root;
}
int depthTree(Node* root) {
if (root == nullptr) {
return 0;
} else {
int lh = depthTree(root->left);
int rh = depthTree(root->right);
return ((lh > rh) ? lh : rh) + 1;
}
}
int countNodes(Node* root, T data) {
if (root == nullptr) {
return 0;
} else {
if (root->data > data)
return countNodes(root->left, data);
if (root->data < data)
return countNodes(root->right, data);
return root->count;
}
}
};

#endif  // INCLUDE_BST_H_
