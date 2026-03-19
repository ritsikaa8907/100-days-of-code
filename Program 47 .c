//Problem: Height of Binary Tree

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

int height(struct Node* root) {
    if (root == NULL) {
        return 0;
    }

    int left = height(root->left);
    int right = height(root->right);

    return (left > right ? left : right) + 1;
}

int main() {
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    int h = height(root);

    printf("Height of Binary Tree: %d\n", h);

    return 0;
}
