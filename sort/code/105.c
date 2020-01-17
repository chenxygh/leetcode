/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize){
    if (preorderSize <= 0) return NULL;
    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->val = preorder[0];
    int index = 0;
    while (index < inorderSize && inorder[index] != preorder[0]) ++index;

    root->left = buildTree(preorder + 1, index, inorder, index);
    root->right = buildTree(preorder + 1 + index, preorderSize - (index + 1), inorder + index + 1, inorderSize - (index + 1));

    return root;
}
