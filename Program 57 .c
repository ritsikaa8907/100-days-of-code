//Convert a binary tree into its mirror image by swapping left and right children at every node.
#include <stdio.h>
#include <stdlib.h>

// Structure for a tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to convert tree into its mirror
void mirror(struct Node* root) {
    if (root == NULL)
        return;

    // Swap left and right
    struct Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    // Recursively mirror subtrees
    mirror(root->left);
    mirror(root->right);
}

// Inorder traversal to check result
void inorder(struct Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Driver code
int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);

    printf("Inorder before mirror:\n");
    inorder(root);

    mirror(root);

    printf("\nInorder after mirror:\n");
    inorder(root);

    return 0;
}
