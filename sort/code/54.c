/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    returnSize[0] = 0;
    if (matrixSize == 0 || matrixColSize == NULL) return NULL;    
    
    int row = matrixSize, column = matrixColSize[0], x = 0, y = -1;
    int *res = (int *) malloc (sizeof(int) * (row * column)), length = 0;
    while (row > 0 && column > 0) {
        for (int i = 0; i < column; ++i) {
            res[length++] = matrix[x][++y];
        }
        if (--row == 0) break;
        for (int i = 0; i < row; ++i) {
            res[length++] = matrix[++x][y];
        }
        if (--column == 0) break;
        for (int i = 0; i < column; ++i) {
            res[length++] = matrix[x][--y];
        }
        if (--row == 0) break;
        for (int i = 0; i < row; ++i) {
            res[length++] = matrix[--x][y];
        }
        --column;
    }

    returnSize[0] = length;
    return res;
}
