// int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize){
//     unsigned int a[obstacleGridColSize[0]], b[obstacleGridColSize[0]];
//     unsigned int *preResult = a, *result = b;
//     int k = 0;
//     while (k < obstacleGridColSize[0] && obstacleGrid[0][k] == 0) preResult[k++] = 1;
//     while (k < obstacleGridColSize[0]) preResult[k++] = 0;

//     for (int i = 1; i < obstacleGridSize; ++i) {
//         result[0] = preResult[0] == 0? 0: !obstacleGrid[i][0];
//         for (int j = 1; j < obstacleGridColSize[0]; ++j) {
//             result[j] = obstacleGrid[i][j] == 0? result[j - 1] + preResult[j]: 0;
//         }
//         unsigned int *temp = result;
//         result = preResult;
//         preResult = temp;
//     }

//     return preResult[obstacleGridColSize[0] - 1];
// }

int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize){
    int k = 0;
    while (k < obstacleGridColSize[0] && obstacleGrid[0][k] == 0) obstacleGrid[0][k++] = 1;
    while (k < obstacleGridColSize[0]) obstacleGrid[0][k++] = 0;

    for (int i = 1; i < obstacleGridSize; ++i) {
        obstacleGrid[i][0] = obstacleGrid[i - 1][0] == 0? 0: !obstacleGrid[i][0];
        for (int j = 1; j < obstacleGridColSize[0]; ++j) {
            obstacleGrid[i][j] = obstacleGrid[i][j] == 0? obstacleGrid[i][j - 1] + obstacleGrid[i - 1][j]: 0;
        }
    }

    return obstacleGrid[obstacleGridSize - 1][obstacleGridColSize[0] - 1];
}
