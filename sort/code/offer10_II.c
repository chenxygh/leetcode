int numWays(int n){
    if (n <= 1) return 1;
    int f0 = 1, f1 = 1, f2 = f0 + f1;
    for (int i = 3; i <= n; ++i) {
        f0 = f1 % 1000000007;
        f1 = f2 % 1000000007;
        f2 = f1 + f0;
    }
    return f2 % 1000000007;
}
