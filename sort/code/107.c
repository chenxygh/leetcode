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

#define MAXSIZE 1100

int** levelOrderBottom(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    int **res = (int **)malloc(sizeof(int *) * MAXSIZE);
    res[MAXSIZE - 1] = (int *)malloc(sizeof(int) * 1);
    returnColumnSizes[0] = (int *)malloc(sizeof(int) * MAXSIZE);
    returnSize[0] = 0;
    struct TreeNode *Queue[MAXSIZE];
    int front = 0, rear = 0, last = 0;
    Queue[root? rear++: rear] = root;
    last = rear;

    int cnt = 0;
    while (front < rear) {
        struct TreeNode *p = Queue[front++];
        res[MAXSIZE - 1 - returnSize[0]][cnt++] = p->val;
        if (p->left) Queue[rear++] = p->left;
        if (p->right) Queue[rear++] = p->right;

        if (front == last) {
            last = rear;
            returnColumnSizes[0][MAXSIZE - 1 - returnSize[0]++] = cnt;
            res[MAXSIZE - 1 - returnSize[0]] = (int *)malloc(sizeof(int) * 500);
            cnt = 0;
        }
    }

    returnColumnSizes[0] += MAXSIZE - returnSize[0];
    return res + MAXSIZE - returnSize[0];
}

