//Construct a binary tree from given inorder and postorder traversal arrays.
#include <stdlib.h>

int findIndex(int* inorder, int start, int end, int val) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == val)
            return i;
    }
    return -1;
}

struct TreeNode* build(int* inorder, int* postorder,
                       int inStart, int inEnd,
                       int* postIndex) {

    if (inStart > inEnd)
        return NULL;

    int rootVal = postorder[*postIndex];
    (*postIndex)--;

    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = rootVal;
    root->left = root->right = NULL;

    int inIndex = findIndex(inorder, inStart, inEnd, rootVal);

    root->right = build(inorder, postorder, inIndex + 1, inEnd, postIndex);
    root->left  = build(inorder, postorder, inStart, inIndex - 1, postIndex);

    return root;
}

struct TreeNode* buildTree(int* inorder, int inorderSize,
                           int* postorder, int postorderSize) {

    int postIndex = postorderSize - 1;

    return build(inorder, postorder,
                 0, inorderSize - 1,
                 &postIndex);
}
