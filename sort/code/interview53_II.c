int missingNumber(int* nums, int numsSize){
    int left = 0, right = numsSize - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == mid) left = mid + 1;
        else right = mid - 1;
    }
    return left;
}
