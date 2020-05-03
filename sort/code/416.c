int max (int a, int b) {
    return a > b? a: b;
}

// bool zeroOne (int *nums, int numsSize, int capacity) {
//     int dp[capacity + 1];
//     for (int i = 0; i <= capacity; ++i) dp[i] = 0;
//     for (int i = 0; i < numsSize; ++i) {
//         for (int j = capacity; j >= nums[i]; --j) {
//             dp[j] = max (dp[j], dp[j - nums[i]] + nums[i]);
//         }
//     }
//     return dp[capacity] == capacity;
// }

bool zeroOne (int *nums, int numsSize, int capacity) {
    bool dp[capacity + 1];
    for (int i = 1; i <= capacity; ++i) dp[i] = false;
    dp[0] = true;
    for (int i = 0; i < numsSize; ++i) {
        for (int j = capacity; j >= nums[i]; --j) {
            dp[j] = dp[j] || dp[j - nums[i]];
        }
    }
    return dp[capacity];
}

bool canPartition(int* nums, int numsSize){
    int sum = 0;
    for (int i = 0; i < numsSize; ++i) sum += nums[i];
    return sum % 2? false: zeroOne (nums, numsSize, sum / 2);
}
