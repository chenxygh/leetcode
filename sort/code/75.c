void swap (int *nums, int i, int j) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

void sortColors(int* nums, int numsSize){
    for (int i = 0, j = 0, k = numsSize - 1; j <=k;) {
        if (nums[j] == 0) swap (nums, i++, j++);
        else if (nums[j] == 2) swap (nums, j, k--);
        else ++j;
    }
}
