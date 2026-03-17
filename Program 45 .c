//Find the height (maximum depth) of a given binary tree.


int maxDepth(struct TreeNode* root) {
    if (root == NULL)
        return 0;

    int leftHeight = maxDepth(root->left);
    int rightHeight = maxDepth(root->right);

    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}
