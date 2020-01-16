int removeDuplicates(int* nums, int numsSize){
    int i = 0;
    for (int j = 1, cnt = 1; j < numsSize;) {
        if (nums[i] != nums[j]) {
            cnt = 1;
            nums[++i] = nums[j++];
        } else if (++cnt > 2) {
            cnt = 1;
            while (j < numsSize && nums[i] == nums[j]) ++j;
        } else {
            nums[++i] = nums[j++];
        }
    }

    return numsSize? i + 1: 0;
}
