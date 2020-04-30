/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int max (int a, int b) {
    return a > b? a: b;
}

int judge (struct TreeNode *root, bool *balance) {
    if (root == NULL) {
        *balance = true;
        return 0;
    }
    bool leftBalance = false, rightBalance = false;
    int leftDepth = judge (root->left, &leftBalance);
    int rightDepth = judge (root->right, &rightBalance);
    *balance = leftBalance && rightBalance && abs (leftDepth - rightDepth) <= 1;
    return max (leftDepth, rightDepth) + 1;
}

bool isBalanced(struct TreeNode* root){
    bool balance = false;
    judge (root, &balance);
    return balance;
}
