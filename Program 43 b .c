//Given the root of a binary tree, return the inorder traversal of its nodes' values.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void inorder(struct TreeNode* root, int* arr, int* size)
{
    if(root == NULL)
        return;

    inorder(root->left, arr, size);

    arr[(*size)++] = root->val;

    inorder(root->right, arr, size);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize)
{
    int* result = malloc(1000 * sizeof(int));
    *returnSize = 0;

    inorder(root, result, returnSize);

    return result;
}
