/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize){
    if (preorderSize <= 0) {
        return NULL;
    }
    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->val = preorder[0];
    int index = 0;
    while (index < preorderSize && inorder[index] != preorder[0]) ++index; // index 不会越界， 但这是好习惯
    root->left = buildTree (preorder + 1, index, inorder, index);
    root->right = buildTree (preorder + 1 + index, preorderSize - 1 - index, inorder + index + 1, preorderSize - 1 - index);

    return root;
}
