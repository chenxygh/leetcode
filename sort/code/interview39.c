int missingNumber(int* nums, int numsSize){
    int left = 0, right = numsSize - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == mid) left = mid + 1;
        else right = mid - 1;
    }
    return left;
}
int majorityElement(int* nums, int numsSize){
    int major = nums[0];
    int cnt = 1;
    for (int i = 1; i < numsSize; ++i) {
        if (major == nums[i]) ++cnt;
        else {
            if (--cnt == 0) {
                major = nums[++i];
                cnt = 1;
            }
        }
    }

    return major;
}
