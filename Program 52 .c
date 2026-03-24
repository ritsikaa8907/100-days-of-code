//Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Tree.
struct TreeNode* insertIntoBST(struct TreeNode* root, int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;

    if (root == NULL) return newNode;

    struct TreeNode* curr = root;

    while (1) {
        if (val < curr->val) {
            if (curr->left == NULL) {
                curr->left = newNode;
                break;
            }
            curr = curr->left;
        } else {
            if (curr->right == NULL) {
                curr->right = newNode;
                break;
            }
            curr = curr->right;
        }
    }

    return root;
}
