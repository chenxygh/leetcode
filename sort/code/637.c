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
double* averageOfLevels(struct TreeNode* root, int* returnSize){
    double *res = (double *)malloc(sizeof(double) * 1000);
    
    struct TreeNode *Queue[10000];
    int front = 0;
    int rear = 0;
    Queue[rear++] = root;
    int last = rear;

    int level = 0;
    double sum = 0.0;
    int cnt = 0;
    while (front < rear) {
        struct TreeNode *p = Queue[front++];
        sum += p->val;
        cnt++;
        if (p->left) Queue[rear++] = p->left;
        if (p->right) Queue[rear++] = p->right;
        if (front == last) {
            last = rear;
            // res = realloc(res, ++level * sizeof(double));
            res[level++] = sum / cnt;
            sum = cnt = 0;
        }
    }

    returnSize[0] = level;
    return res;
}
