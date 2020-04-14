/*
    F(m, n) = F(m, n - 1) + F(m - 1, n)
    n == 1, F(m, n) = F(m - 1, 1) = ... = F(1, 1) = 1
    m == 1, F(m, n) = F(1, n - 1) = ... = F(1, 1) = 1
*/
int uniquePaths(int m, int n){
    if (n == 1 || m == 1) return 1;
    int a[n + 1], b[n + 1];
    int *preResult = a, *result = b;
    for (int i = 1; i <= n; ++i) {
        preResult[i] = 1;
    }
    result[1] = 1;
    for (int i = 2; i <= m; ++i) {
        result[1] = 1;
        for (int j = 2; j <= n; ++j) {
            result[j] = result[j - 1] + preResult[j];
        }
        int *temp = preResult;
        preResult = result;
        result = temp;
    }
    return preResult[n];
}
