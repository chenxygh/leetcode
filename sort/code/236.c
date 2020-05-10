/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool judge (struct TreeNode *root, struct TreeNode *p, struct TreeNode *q, struct TreeNode **res) {
    if (res[0]) return false;
    if (root == NULL) return false;
    bool lson = judge (root->left, p, q, res);
    bool rson = judge (root->right, p, q, res);
    if (lson && rson || ((root == p || root == q) && (lson || rson))) res[0] = root;
    return lson || rson || (root == p || root == q);    
}
    

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    struct TreeNode *res = NULL;
    judge (root, p, q, &res);
    return res;
}
