/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* invertTree(struct TreeNode* root){
    if (root) {
        invertTree (root->left);
        invertTree (root->right);
        struct TreeNode *p = root->left;
        root->left = root->right;
        root->right = p;
    }
    return root;
}
