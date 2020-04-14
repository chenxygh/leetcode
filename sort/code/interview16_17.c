#define INT_MIN -2147483648

int max (int a, int b) {
    return a > b? a: b;
}

// int maxSubArray(int* nums, int numsSize){
//     int res = INT_MIN, sum = 0;
//     for (int i = 0; i < numsSize; ++i) {
//         sum = sum > 0? sum + nums[i]: nums[i];
//         res = sum > res? sum: res;
//     }
//     return res;
// }

int maxSubArray(int* nums, int numsSize){
    if (numsSize == 1) return nums[0];
    int mid = numsSize / 2;
    int leftVal = maxSubArray (nums, mid);
    int rightVal = maxSubArray (nums + mid, numsSize - mid);
    int leftBorderVal = INT_MIN, rightBorderVal = INT_MIN;
    for (int i = mid - 1, sum = 0; i >= 0; --i) {
        sum += nums[i];
        leftBorderVal = sum > leftBorderVal? sum: leftBorderVal;
    }
    for (int i = mid, sum = 0; i < numsSize; ++i) {
        sum += nums[i];
        rightBorderVal = sum > rightBorderVal? sum: rightBorderVal;
    }
    int crossVal = leftBorderVal + rightBorderVal;
    return max (max (leftVal, rightVal), crossVal);
}
