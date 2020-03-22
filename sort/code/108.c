/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* sortedArrayToBST(int* nums, int numsSize){
    if (numsSize <= 0) return NULL;
    int mid = numsSize / 2;
    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->val = nums[mid];
    root->left = sortedArrayToBST (nums, mid);
    root->right = sortedArrayToBST (nums + mid + 1, numsSize - mid - 1);

    return root;
}
