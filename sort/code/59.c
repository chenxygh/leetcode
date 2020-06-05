/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generateMatrix(int n, int* returnSize, int** returnColumnSizes){
    returnSize[0] = 0;
    returnColumnSizes[0] = NULL;
    if (n == 0) return NULL;

    returnColumnSizes[0] = (int *) malloc (sizeof(int) * n);
    returnSize[0] = n;
    int x = 0, y = -1, **res = (int **)malloc (sizeof(int *) * n), row = n, column = n;
    for (int i = 0; i < n; ++i) {
        res[i] = (int *)malloc (sizeof (int) * n);
        returnColumnSizes[0][i] = n;
    }
    int val = 0;
    while (row > 0 && column > 0) {
        for (int i = 0; i < column; ++i) {
            res[x][++y] = ++val;
        }
        if (--row == 0) break;
        for (int i = 0; i < row; ++i) {
            res[++x][y] = ++val;
        }
        if (--column == 0) break;
        for (int i = 0; i < column; ++i) {
            res[x][--y] = ++val;
        }
        if (--row == 0) break;
        for (int i = 0; i < row; ++i) {
            res[--x][y] = ++val;
        }
        --column;
    }

    return res;
}
