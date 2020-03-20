/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


// struct TreeNode* searchBST(struct TreeNode* root, int val){
//     while (root && root->val != val) {
//         root = root->val > val? root->left: root->right;
//     }
//     return root;
// }

struct TreeNode* searchBST(struct TreeNode* root, int val){
    if (root == NULL || root->val == val) return root;
    return root->val > val? searchBST (root->left, val): searchBST (root->right, val);
}
