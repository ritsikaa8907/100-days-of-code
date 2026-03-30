//Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

#include <stdlib.h>
int findIndex(int* inorder, int start, int end, int val) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == val)
            return i;
    }
    return -1;
}

struct TreeNode* build(int* preorder, int* inorder,
                       int preStart, int preEnd,
                       int inStart, int inEnd) {

    if (preStart > preEnd || inStart > inEnd)
        return NULL;

    int rootVal = preorder[preStart];

    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = rootVal;
    root->left = root->right = NULL;

    int inIndex = findIndex(inorder, inStart, inEnd, rootVal);
    int leftSize = inIndex - inStart;

    root->left = build(preorder, inorder,
                       preStart + 1, preStart + leftSize,
                       inStart, inIndex - 1);

    root->right = build(preorder, inorder,
                        preStart + leftSize + 1, preEnd,
                        inIndex + 1, inEnd);

    return root;
}

struct TreeNode* buildTree(int* preorder, int preorderSize,
                           int* inorder, int inorderSize) {

    return build(preorder, inorder,
                 0, preorderSize - 1,
                 0, inorderSize - 1);
}
