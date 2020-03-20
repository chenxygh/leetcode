/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* insertIntoBST(struct TreeNode* root, int val){
    struct TreeNode **p = &root;

    while (p[0]) {
        p = p[0]->val > val? &(p[0]->left): &(p[0]->right);
    }
    p[0] = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    p[0]->val = val;
    p[0]->left = p[0]->right = NULL;

    return root;
}
