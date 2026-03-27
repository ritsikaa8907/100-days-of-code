//Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

#include <stdlib.h>

int* rightSideView(struct TreeNode* root, int* returnSize) {
    if (!root) {
        *returnSize = 0;
        return NULL;
    }

    int capacity = 100;
    int* result = malloc(capacity * sizeof(int));

    int qCap = 100;
    struct TreeNode** queue = malloc(qCap * sizeof(struct TreeNode*));
    int front = 0, rear = 0;

    queue[rear++] = root;
    *returnSize = 0;

    while (front < rear) {
        int size = rear - front;

        if (*returnSize >= capacity) {
            capacity *= 2;
            result = realloc(result, capacity * sizeof(int));
        }

        for (int i = 0; i < size; i++) {
            struct TreeNode* node = queue[front++];

            if (i == size - 1) {
                result[*returnSize] = node->val;
                (*returnSize)++;
            }

            if (node->left) {
                if (rear >= qCap) {
                    qCap *= 2;
                    queue = realloc(queue, qCap * sizeof(struct TreeNode*));
                }
                queue[rear++] = node->left;
            }

            if (node->right) {
                if (rear >= qCap) {
                    qCap *= 2;
                    queue = realloc(queue, qCap * sizeof(struct TreeNode*));
                }
                queue[rear++] = node->right;
            }
        }
    }

    return result;
}
