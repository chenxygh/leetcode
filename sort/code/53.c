// int maxSubArray(int* nums, int numsSize){
//     int res = nums[0], sum = 0;
//     for (int i = 0; i < numsSize; ++i) {
//         sum = sum > 0? sum + nums[i]: nums[i];
//         res = sum > res? sum: res;
//     }

//     return res;
// }

int maxSubArray(int* nums, int numsSize){
    if (numsSize == 1) return nums[0];
    int mid = numsSize / 2;
    int leftSum = maxSubArray (nums, mid);
    int rightSum = maxSubArray (nums + mid, numsSize - mid);
    int leftBorderSum = nums[mid - 1], rightBorderSum = nums[mid];
    for (int i = mid - 1, sum = 0; i >= 0; --i) {
        sum += nums[i];
        leftBorderSum = sum > leftBorderSum? sum: leftBorderSum;
    }
    for (int i = mid, sum = 0; i < numsSize; ++i) {
        sum += nums[i];
        rightBorderSum = sum > rightBorderSum? sum: rightBorderSum;
    }
    int crossSum = rightBorderSum + leftBorderSum;
    int maxSum = leftSum > rightSum? leftSum: rightSum;
    return maxSum > crossSum? maxSum: crossSum;
}
