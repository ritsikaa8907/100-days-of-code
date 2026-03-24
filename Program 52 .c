//Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Tree.
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* LCA(struct Node* root, struct Node* p, struct Node* q) {
    if (root == NULL || root == p || root == q) {
        return root;
    }

    struct Node* left = LCA(root->left, p, q);
    struct Node* right = LCA(root->right, p, q);

    if (left != NULL && right != NULL) {
        return root;
    }

    return left != NULL ? left : right;
}

int main() {
    struct Node* root = createNode(3);
    root->left = createNode(5);
    root->right = createNode(1);
    root->left->left = createNode(6);
    root->left->right = createNode(2);
    root->right->left = createNode(0);
    root->right->right = createNode(8);
    root->left->right->left = createNode(7);
    root->left->right->right = createNode(4);

    struct Node* p = root->left;
    struct Node* q = root->left->right->right;

    struct Node* lca = LCA(root, p, q);

    if (lca != NULL) {
        printf("LCA: %d\n", lca->data);
    }

    return 0;
}
