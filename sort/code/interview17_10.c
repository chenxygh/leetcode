int majorityElement(int* nums, int numsSize){
    int major = nums[0];
    int cnt = 0;
    for (int i = 0; i < numsSize; ++i) {
        major = cnt? major: nums[i];
        cnt = major == nums[i]? cnt + 1: cnt - 1;
    }
    return major;
}
