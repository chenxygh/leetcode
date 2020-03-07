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
int* levelOrder(struct TreeNode* root, int* returnSize){
    int *res = (int *)malloc(sizeof(int) * 1100);
    returnSize[0] = 0;
    struct TreeNode * Queue[1100];
    int front = 0, rear = 0;
    Queue[root? rear++: rear] = root;

    while (front < rear) {
        struct TreeNode *p = Queue[front++];
        res[returnSize[0]++] = p->val;
        if (p->left) Queue[rear++] = p->left;
        if (p->right) Queue[rear++] = p->right;
    }

    return res;
}
