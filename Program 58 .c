//Construct a binary tree from given preorder and inorder traversal arrays.
int findIndex(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}

struct TreeNode* buildTreeHelper(int preorder[], int inorder[],
                                 int preStart, int preEnd,
                                 int inStart, int inEnd) {

    if (preStart > preEnd || inStart > inEnd)
        return NULL;

    // Root from preorder
    int rootVal = preorder[preStart];

    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = rootVal;
    root->left = root->right = NULL;

    // Find root in inorder
    int rootIndex = findIndex(inorder, inStart, inEnd, rootVal);

    int leftSize = rootIndex - inStart;

    // Build left subtree
    root->left = buildTreeHelper(preorder, inorder,
                                 preStart + 1, preStart + leftSize,
                                 inStart, rootIndex - 1);

    // Build right subtree
    root->right = buildTreeHelper(preorder, inorder,
                                  preStart + leftSize + 1, preEnd,
                                  rootIndex + 1, inEnd);

    return root;
}

struct TreeNode* buildTree(int* preorder, int preorderSize,
                           int* inorder, int inorderSize) {

    return buildTreeHelper(preorder, inorder,
                           0, preorderSize - 1,
                           0, inorderSize - 1);
}
