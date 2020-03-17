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
int* postorderTraversal(struct TreeNode* root, int* returnSize){
    int *res = (int *)malloc(sizeof(int) * 100);
    returnSize[0] = 0;
    struct TreeNode *Stack[100];
    int top = -1;
    struct TreeNode *pre = NULL;
    
    while (root || top != -1) {
        if (root) {
            Stack[++top] = root;
            root = root->left;
        } else {
            struct TreeNode *p = Stack[top];
            if (p->right && p->right != pre) {
                root = p->right;
            } else {
                --top;
                res[returnSize[0]++] = p->val;
                pre = p;
            }
        }
    }

    return res;
}
