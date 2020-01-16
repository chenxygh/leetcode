#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findErrorNums(int* nums, int numsSize, int* returnSize){
    int dict[numsSize + 1];
    int *res = (int *)malloc(2 * sizeof(int));
    returnSize[0] = 2;

    for (int i = 0; i < numsSize + 1; ++i) dict[i] = 0;
    for (int i = 0; i < numsSize; ++i) if (++dict[nums[i]] > 1) res[0] = nums[i];
    int i = 0;
    while (i < numsSize && dict[nums[i]] != 0) ++i;
    res[1] = nums[i];

    return res;
}

int main(int argc, char const *argv[])
{
	int returnSize = 0;
	int nums[] = {1, 2, 2, 4};

	int *res = findErrorNums (nums, 4, &returnSize);

	for (int i = 0; i < returnSize; ++i) printf(" %d", res[i]);
	return 0;
}
