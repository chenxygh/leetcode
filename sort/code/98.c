/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

// method 1: pre order  recursion
// bool judge (struct TreeNode* root, struct TreeNode *min, struct TreeNode *max){
//     if (root == NULL) return true;
//     if (min && min->val >= root->val) return false;
//     if (max && max->val <= root->val) return false;
//     return judge (root->left, min, root) && judge (root->right, root, max);
// }

// bool isValidBST(struct TreeNode* root){
//     return judge (root, NULL, NULL);
// }

// method 2: in order  recursion
// bool inOrder (struct TreeNode *root, struct TreeNode **pre) {
//     if (root) {
//         if (!inOrder (root->left, pre)) return false;
//         if (pre[0] && pre[0]->val >= root->val) return false;
//         pre[0] = root;
//         if (!inOrder (root->right, pre)) return false;
//     }
//     return true;
// }

// bool isValidBST(struct TreeNode* root){
//     struct TreeNode *pre = NULL;
//     return inOrder (root, &pre);
// }


// method 2: in order  iteration
bool isValidBST(struct TreeNode* root){
    struct TreeNode *stack[10000], *pre = NULL;
    int top = -1;
    while (top != -1 || root) {
        if (root) {
            stack[++top] = root;
            root = root->left;
        } else {
            root = stack[top--];
            if (pre && pre->val >= root->val) return false;
            pre = root;
            root = root->right;
        }
    }
    return true;
}
