int max (int a, int b) {
    return a > b? a: b;
}

/*
    F(N) = max (F(N - 1), F(N - 2) + P[N])
    F(1) = P[1];
    F(2) = max (0 + P[2], P[1]);
    F(0) = 0;
    F(-1) = 0;
*/
int rob(int* nums, int numsSize){
    int f0, f1, f2;
    f0 = f1 = f2 = 0;
    for (int i = 0; i < numsSize; ++i) {
        f2 = max (f1, f0 + nums[i]);
        f0 = f1;
        f1 = f2;
    }
    return f2;
}
