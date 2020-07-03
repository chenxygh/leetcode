// int xorOperation(int n, int start){
//     unsigned int res = 0;
//     for (int i = 0; i < n; ++i) res ^= start + 2 * i;
//     return res;
// }

int func (int n, int start) {
    return (n % 2? start + n - 1: 0) ^ ((n / 2) % 2);
}

int xorOperation(int n, int start){
    unsigned int res = 0, last = start % 2? n % 2: 0;
    start >>= 1;
    res = start % 2? (start - 1) ^ func (n + 1, start - 1): func (n, start);
    return (res << 1) | last;
}
