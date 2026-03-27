//Perform zigzag (spiral) level order traversal of a binary tree. Alternate levels should be traversed left-to-right and right-to-left.
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = data;
    n->left = n->right = NULL;
    return n;
}

void zigzagTraversal(struct Node* root) {
    if (!root) return;

    struct Node* queue[MAX];
    int front = 0, rear = 0;

    queue[rear++] = root;
    int leftToRight = 1;

    while (front < rear) {
        int size = rear - front;
        int level[MAX];

        for (int i = 0; i < size; i++) {
            struct Node* curr = queue[front++];

            int index = leftToRight ? i : (size - 1 - i);
            level[index] = curr->data;

            if (curr->left)
                queue[rear++] = curr->left;

            if (curr->right)
                queue[rear++] = curr->right;
        }

        for (int i = 0; i < size; i++) {
            printf("%d ", level[i]);
        }

        printf("\n");
        leftToRight = !leftToRight;
    }
}

int main() {
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    zigzagTraversal(root);

    return 0;
}
