/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize){
    if (inorderSize <= 0) return NULL;
    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->val = postorder[postorderSize - 1];

    int index = 0;
    while (index < inorderSize && inorder[index] != root->val) ++index;

    root->left = buildTree(inorder, index, postorder, index);
    root->right = buildTree(inorder + index + 1, inorderSize - (index + 1), postorder + index, postorderSize - (index + 1));
    return root;
}
