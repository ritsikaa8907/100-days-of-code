//Given the root of a binary tree, flatten the tree into a "linked list":
void flattenTree(struct TreeNode* root, struct TreeNode** prev) {
    if (root == NULL)
        return;

    flattenTree(root->right, prev);
    flattenTree(root->left, prev);

    root->right = *prev;
    root->left = NULL;

    *prev = root;
}

void flatten(struct TreeNode* root) {
    struct TreeNode* prev = NULL;
    flattenTree(root, &prev);
}
