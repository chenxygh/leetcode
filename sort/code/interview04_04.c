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
int judge (struct TreeNode *root, int *balance) {
    if (root == NULL) {
        *balance = 1;
        return 0;
    }
    int leftDepth = 0, rightDepth = 0, leftBalance = 0, rightBalance = 0;
    leftDepth = judge (root->left, &leftBalance);
    rightDepth = judge (root->right, &rightBalance);
    
    *balance = leftBalance && rightBalance && (abs (leftDepth - rightDepth) <= 1);
    return max (leftDepth, rightDepth) + 1;
}

bool isBalanced(struct TreeNode* root){
    int balance = 0;
    judge (root, &balance);
    return balance;
}
