#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// int* searchRange(int* nums, int numsSize, int target, int* returnSize){
//     returnSize[0] = 2;
//     int *res = (int *)malloc(sizeof(int) * 2);

//     int i = 0;
//     while (i < numsSize && nums[i] != target) ++i;
//     if (i >= numsSize) {
//         res[0] = -1; res[1] = -1;
//     } else {
//         res[0] = i;
//         printf("%d\n", res[0]);
//         while (i < numsSize && nums[i] == target) ++i;
//         res[1] = i - 1;
//     }

//     return res;
// }

// int* searchRange(int* nums, int numsSize, int target, int* returnSize){
//     returnSize[0] = 2;
//     int *res = (int *)malloc(sizeof(int) * 2);
//     res[0] = res[1] = -1;

//     if (numsSize == 0) return res;

//     int left = 0; 
//     int right = numsSize - 1;
//     int mid = 0;
//     while (left <= right) {
//         mid = (left + right) / 2;
//         if (nums[mid] < target) left = mid + 1;
//         else if (nums[mid] >= target) right = mid - 1;
//     }
//     printf("%d\n", mid);
//     if (left < numsSize && nums[left] == target) {
//         res[0] = left;
//         while (left < numsSize && nums[left] == target) ++left;
//         res[1] = left - 1;
//     }

//     return res;
// }

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// 无须走完
int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    int left = 0, right = numsSize - 1;
    int *res = (int *)malloc(sizeof(int) * 2);
    res[0] = res[1] = -1;
    returnSize[0] = 2;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target) left = mid + 1;
        else if (nums[mid] > target) right = mid - 1;
        else {
            int n = mid;
            for (; n >= 0 && nums[n] == target; --n);
            res[0] = n >= 0? n + 1: 0;
            n = mid + 1;
            for (; n < numsSize && nums[n] == target; ++n);
            res[1] = n < numsSize? n - 1: numsSize - 1;
            return res;
        }
    }
    return res;
}

int main(int argc, char const *argv[])
{
	int nums[] = {1, 2, 3};
	int returnSize = 0;
	int *res = searchRange (nums, 3, 2, &returnSize);
	for (int i = 0; i < returnSize; ++i) printf(" %d", res[i]);
	return 0;
}
