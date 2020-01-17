/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    int **res = (int **)malloc(sizeof(int *) * 1000);
    returnColumnSizes[0] = (int *)malloc(sizeof(int) * 1000);
    int *nums = (int *)malloc(sizeof(int) * 10000);
    struct TreeNode * Queue[10000];
    int front, rear, level, last;
    front = rear = level = 0;
    int n = 0;
    int cnt = 0;
    Queue[root? rear++: rear] = root;
    last = rear;
    while (front < rear) {
        struct TreeNode *p = Queue[front++];
        cnt++;
        nums[n++] = p->val;
        if (p->left) Queue[rear++] = p->left;
        if (p->right) Queue[rear++] = p->right;

        if (front == last) {
            last = rear;
            returnColumnSizes[0][level] = cnt;
            res[level++] = nums + n - cnt;
            cnt = 0;
        }
    }

    returnSize[0] = level;
    return res;
}
