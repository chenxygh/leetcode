/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* preorderTraversal(struct TreeNode* root, int* returnSize){
    int *res = (int *)malloc(sizeof(int) * 100);
    returnSize[0] = 0;
    struct TreeNode *Stack[100];
    int top = -1;

    while (root || top != -1) {
        if (root) {
            res[returnSize[0]++] = root->val;
            Stack[++top] = root;
            root = root->left;
        } else {
            root = Stack[top--];
            root = root->right;
        }
    }

    return res;
}
