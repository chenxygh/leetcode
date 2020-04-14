int max (int a, int b) {
    return a > b? a: b;
}
int massage(int* nums, int numsSize){
    int f0, f1, f2;
    f0 = f1 = f2 = 0;
    for (int i = 0; i< numsSize; ++i) {
        f2 = max (f1, f0 + nums[i]);
        f0 = f1;
        f1 = f2;
    }
    return f2;
}
