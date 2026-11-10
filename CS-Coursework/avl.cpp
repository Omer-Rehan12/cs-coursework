#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node *left, *right;
    int height;
};

// Height function
int height(Node* p) {
    return p ? p->height : 0;
}

// Create new node
Node* newNode(int data) {
    Node* p = new Node;
    p->data = data;
    p->left = p->right = NULL;
    p->height = 1;
    return p;
}

// Balance Factor
int balanceFactor(Node* p) {
    return height(p->left) - height(p->right);
}

// Update node height
void updateHeight(Node* p) {
    p->height = 1 + max(height(p->left), height(p->right));
}

// ----------------------
// ROTATIONS
// ----------------------

// LL Rotation
Node* LLrotation(Node* p) {
    Node* pl = p->left;
    Node* plr = pl->right;

    pl->right = p;
    p->left = plr;

    updateHeight(p);
    updateHeight(pl);

    return pl;
}

// RR Rotation
Node* RRrotation(Node* p) {
    Node* pr = p->right;
    Node* prl = pr->left;

    pr->left = p;
    p->right = prl;

    updateHeight(p);
    updateHeight(pr);

    return pr;
}

// LR Rotation
Node* LRrotation(Node* p) {
    p->left = RRrotation(p->left);
    return LLrotation(p);
}

// RL Rotation
Node* RLrotation(Node* p) {
    p->right = LLrotation(p->right);
    return RRrotation(p);
}

// AVL INSERTION
Node* insert(Node* root, int key) {

    if (root == NULL)
        return newNode(key);

    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);

    updateHeight(root);

    int bf = balanceFactor(root);

    // LEFT-LEFT CASE
    if (bf > 1 && key < root->left->data)
        return LLrotation(root);

    // RIGHT-RIGHT CASE
    if (bf < -1 && key > root->right->data)
        return RRrotation(root);

    // LEFT-RIGHT CASE
    if (bf > 1 && key > root->left->data)
        return LRrotation(root);

    // RIGHT-LEFT CASE
    if (bf < -1 && key < root->right->data)
        return RLrotation(root);

    return root;
}

// Simple preorder print
void preorder(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    Node* root = NULL;

    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 10);   // LL rotation
    root = insert(root, 40);
    root = insert(root, 50);   // RR rotation

    cout << "AVL Tree (Preorder): ";
    preorder(root);
}
