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
int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    int **res = (int **)malloc(sizeof(int *) * 1000);
    int *nums = (int *)malloc(sizeof(int) * 10000);
    returnColumnSizes[0] = (int *)malloc(sizeof(int) * 1000);
    struct TreeNode *Queue[10000];
    int front, rear, last, level;
    front = rear = level = 0;
    Queue[root? rear++: rear] = root;
    last = rear;

    int cnt, n, index;
    index = cnt = n = 0;
    index = last - 1;
    while (front < rear) {
        struct TreeNode *p = Queue[front++];
        if (p->left) Queue[rear++] = p->left;
        if (p->right) Queue[rear++] = p->right;
        p = level % 2? Queue[index--]: p;
        cnt++;
        nums[n++] = p->val;

        if (front == last) {
            last = rear;
            index = last - 1;
            returnColumnSizes[0][level] = cnt;
            res[level++] = nums + n - cnt;
            cnt = 0;
        }
    }

    returnSize[0] = level;
    return res;
}
