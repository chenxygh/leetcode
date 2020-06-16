/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int sumRootToLeaf(struct TreeNode* root){
    unsigned int num = 0, res = 0, top = -1;
    struct TreeNode *stack[1000], *pre = NULL;
    while (top != -1 || root) {
        if (root) {
            num <<= 1;
            num |= root->val;
            stack[++top] = root;
            root = root->left;
        } else {
            root = stack[top];
            if (root->right && root->right != pre) {
                root = root->right;
            } else {
                if (root->left == NULL && root->right == NULL) res += num % 1000000007;
                pre = root;
                --top;
                root = NULL;
                num >>= 1;
            }
        }
    }
    return res % 1000000007;
}
