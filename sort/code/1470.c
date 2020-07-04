/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* shuffle(int* nums, int numsSize, int n, int* returnSize){
    int *res = (int *) malloc (sizeof (int) * numsSize), length = 0;
    for (int i = 0; i < numsSize / 2; ++i) {
        res[length++] = nums[i];
        res[length++] = nums[i + numsSize / 2];
    }
    returnSize[0] = length;
    return res;
}
