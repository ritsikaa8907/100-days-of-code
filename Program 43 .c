//Construct a Binary Tree from the given level-order traversal.
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* buildTree(int arr[], int n)
{
    if(n == 0) return NULL;

    struct Node* root = createNode(arr[0]);

    struct Node* queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;

    int i = 1;

    while(i < n)
    {
        struct Node* current = queue[front++];

        current->left = createNode(arr[i++]);
        queue[rear++] = current->left;

        if(i < n)
        {
            current->right = createNode(arr[i++]);
            queue[rear++] = current->right;
        }
    }

    return root;
}
