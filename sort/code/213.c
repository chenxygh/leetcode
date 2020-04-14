int max (int a, int b) {
    return a > b? a: b;
}

int robOneline (int *nums, int numsSize) {
    int f0, f1, f2;
    f2 = f1 = f0 = 0;
    for (int i = 0; i < numsSize; ++i) {
        f2 = max (f1, f0 + nums[i]);
        f0 = f1;
        f1 = f2;
    }
    return f2;
}

int rob(int* nums, int numsSize){
    if (numsSize == 0) return 0;
    if (numsSize == 1) return nums[0];
    int val_1 = robOneline (nums + 1, numsSize - 1);
    int val_2 = robOneline (nums, numsSize - 1);
    return max (val_1, val_2);
}
