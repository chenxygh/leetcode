#define INT_MAX 2147483647

int min (int a, int b) {
    return a < b? a: b;
}

int minPathSum(int** grid, int gridSize, int* gridColSize){
    int a[gridColSize[0] + 1], b[gridColSize[0] + 1], *pre = a, *res = b;
    pre[0] = res[0] = INT_MAX;
    res[1] = grid[0][0];
    for (int i = 2; i <= gridColSize[0]; ++i) res[i] = grid[0][i - 1] + res[i - 1];
    for (int i = 1; i < gridSize; ++i) {
        int *temp = res;
        res = pre;
        pre = temp;
        for (int j = 1; j <= gridColSize[0]; ++j) {
            res[j] = min (res[j - 1], pre[j]) + grid[i][j - 1];
        }
    }
    return res[gridColSize[0]];
}
