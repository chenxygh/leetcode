/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    returnSize[0] = 0;
    int left = 0, right = numsSize - 1, *res = (int *) malloc (sizeof(int) * 2);
    while (left < right) {
        int val = nums[left] + nums[right];
        if (val < target) ++left;
        else if (val > target) -- right;
        else {
            res[0] = nums[left];
            res[1] = nums[right];
            returnSize[0] = 2;
            return res;
        }
    }

    return NULL;
}
