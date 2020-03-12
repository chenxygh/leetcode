/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* exchange(int* nums, int numsSize, int* returnSize){
    returnSize[0] = numsSize;
    if (numsSize == 0) return NULL;
    int low = 0, high = numsSize - 1;
    int pivot = nums[low];

    while (low < high) {
        while (low < high && (nums[high] % 2 == 0)) --high;
        nums[low] = nums[high];
        while (low < high && (nums[low] % 2 == 1)) ++low;
        nums[high] = nums[low];
    }
    nums[low] = pivot;

    return nums;
}
