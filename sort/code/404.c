/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void preOrder (struct TreeNode *root, struct TreeNode *pre, int *sum) {
    if (root) {
        if (pre && pre->left == root && root->left == NULL && root->right == NULL) sum[0] += root->val;
        preOrder (root->left, root, sum);
        preOrder (root->right, root, sum);
    }
}

int sumOfLeftLeaves(struct TreeNode* root){
    int sum = 0;
    preOrder (root, NULL, &sum);
    return sum;
}
