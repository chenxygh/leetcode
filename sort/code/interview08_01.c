int waysToStep(int n){
    if (n == 1 || n == 2) return n;
    unsigned int nums[4];
    nums[0] = nums[1] = 1;
    nums[2] = 2;
    for (int i = 3; i <= n; ++i) {
        nums[3] = (nums[0] + nums[1] + nums[2]) % 1000000007;
        nums[0] = nums[1];
        nums[1] = nums[2];
        nums[2] = nums[3];
    }

    return nums[3];
}
