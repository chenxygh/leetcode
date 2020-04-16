/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

// iteration
// bool isUnivalTree(struct TreeNode* root){
//     struct TreeNode *stack[100];
//     int top = -1;
//     struct TreeNode *pre = NULL;

//     while (root || top != -1) {
//         if (root) {
//             if (pre && pre->val != root->val) return false;
//             stack[++top] = pre = root;
//             root = root->left;
//         } else {
//             root = stack[top--];
//             root = root->right;
//         }
//     }
//     return true;
// }

// recursion
bool isUnivalTree(struct TreeNode* root){
    if (root == NULL) return true;
    int leftCorrect = root->left == NULL || (root->left->val == root->val && isUnivalTree (root->left));
    int rightCorrect = root->right == NULL || (root->right->val == root->val && isUnivalTree (root->right));
    return leftCorrect && rightCorrect;
}
