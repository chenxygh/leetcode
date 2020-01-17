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
int* largestValues(struct TreeNode* root, int* returnSize){
    int *res = (int *)malloc(sizeof(int) * 1000);
    struct TreeNode * Queue[100000];
    int front, rear, level, last, max;
    front = rear = level = 0;
    max = root? root->val: 0;
    Queue[root? rear++: rear] = root;
    last = rear;
    while (front < rear) {
        struct TreeNode *p = Queue[front++];
        max = p->val > max? p->val: max;
        if (p->left) Queue[rear++] = p->left;
        if (p->right) Queue[rear++] = p->right;

        if (front == last) {
            res[level++] = max;
            max = Queue[front]? Queue[front]->val: 0;
            last = rear;
        }
    }

    returnSize[0] = level;
    return res;
}
