//Check whether a given binary tree satisfies the Min-Heap property.
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

int countNodes(struct Node* root) {
    if (root == NULL)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int isComplete(struct Node* root, int index, int totalNodes) {
    if (root == NULL)
        return 1;

    if (index >= totalNodes)
        return 0;

    return isComplete(root->left, 2 * index + 1, totalNodes) &&
           isComplete(root->right, 2 * index + 2, totalNodes);
}

int isHeap(struct Node* root) {
    if (root->left == NULL && root->right == NULL)
        return 1;

    if (root->right == NULL) {
        return (root->data <= root->left->data) &&
               isHeap(root->left);
    }

    if (root->data <= root->left->data &&
        root->data <= root->right->data) {

        return isHeap(root->left) &&
               isHeap(root->right);
    }

    return 0;
}

int isMinHeap(struct Node* root) {
    int totalNodes = countNodes(root);
    return isComplete(root, 0, totalNodes) && isHeap(root);
}
