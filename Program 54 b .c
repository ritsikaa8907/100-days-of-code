//Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

#include <stdlib.h>

int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if (!root) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }

    int capacity = 100;
    int** result = malloc(capacity * sizeof(int*));
    *returnColumnSizes = malloc(capacity * sizeof(int));

    int qCap = 100;
    struct TreeNode** queue = malloc(qCap * sizeof(struct TreeNode*));
    int front = 0, rear = 0;

    queue[rear++] = root;
    int leftToRight = 1;
    *returnSize = 0;

    while (front < rear) {
        if (*returnSize >= capacity) {
            capacity *= 2;
            result = realloc(result, capacity * sizeof(int*));
            *returnColumnSizes = realloc(*returnColumnSizes, capacity * sizeof(int));
        }

        int size = rear - front;
        result[*returnSize] = malloc(size * sizeof(int));
        (*returnColumnSizes)[*returnSize] = size;

        for (int i = 0; i < size; i++) {
            struct TreeNode* node = queue[front++];

            int index = leftToRight ? i : (size - 1 - i);
            result[*returnSize][index] = node->val;

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

        (*returnSize)++;
        leftToRight = !leftToRight;
    }

    return result;
}
