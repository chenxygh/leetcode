// method 1: DP
// int climbStairs(int n){
//     int nums[n + 1];
//     nums[0] = nums[1] = 1;
//     for (int i = 2; i <= n; ++i) {
//         nums[i] = nums[i - 1] + nums[i -2];
//     }

//     return nums[n];
// }

// recursion
// int climbStairs(int n){
//     if (n == 1) return 1;
//     if (n == 2) return 2;

//     return climbStairs (n - 1) + climbStairs (n -2);
// }

// method 3: DP (no memo array)
int climbStairs (int n) {
    if (n == 1) return 1;
    int f1 = 1, f2 = 1, f3 = f1 + f2;
    for (int i = 2; i <= n; ++i) {
        f3 = f1 + f2;
        f1 = f2;
        f2 = f3;
    }
    return f3;
}
