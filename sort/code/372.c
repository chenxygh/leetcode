int quickPow (int base, int n, int mod) {
    int res = 1;
    while (n) {
        base %= mod;
        if (n & 1) res *= base;
        base *= base;
        n >>= 1;
    }
    return res % mod;
}

int superPow(int a, int* b, int bSize){
    int base = a, res = 1, mod = 1337;
    for (int i = bSize - 1; i >= 0; --i) {
        res *= quickPow (base, b[i], mod) % mod;
        res %= mod;
        base = quickPow (base, 10, mod);
    }
    return res % mod;
}
