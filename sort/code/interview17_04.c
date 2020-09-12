// int missingNumber(int* nums, int numsSize){
//     int dict[numsSize + 1];
//     for (int i = 0; i < numsSize + 1; ++i) dict[i] = 0;
//     for (int i = 0; i < numsSize; ++i) dict[nums[i]] = 1;
//     for (int i = 0; i < numsSize + 1; ++i) if (dict[i] == 0) return i;
//     return 0;
// }

// int missingNumber(int* nums, int numsSize){
//     int res = 0;
//     for (int i = 0; i < numsSize; ++i) res ^= i ^ nums[i];
//     return res ^ numsSize;
// }

int missingNumber(int* nums, int numsSize){
    int res = 0;
    for (int i = 0; i < numsSize; ++i) res += i - nums[i];
    return res + numsSize;
}
