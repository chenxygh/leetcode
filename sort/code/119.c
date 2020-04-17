/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

// two DP array
// int* getRow(int rowIndex, int* returnSize){
//     int *res = (int *)malloc(sizeof(int) * (rowIndex + 1));    
//     int *preResult = (int *)malloc(sizeof(int) * (rowIndex + 1));
//     res[0] = 1;
//     returnSize[0] = rowIndex + 1;
//     for (int i = 1; i <= rowIndex; ++i) {
//         int *temp = res;
//         res = preResult;
//         preResult = temp;
//         res[0] = res[i] = 1;
//         for (int j = 1; j < i; ++j) {
//             res[j] = preResult[j - 1] + preResult[j];
//         }
//     }
//     free(preResult);

//     return res;
// }

// one DP array
int* getRow(int rowIndex, int* returnSize){
    int *res = (int *)malloc(sizeof(int) * (rowIndex + 1));    
    res[0] = 1;    
    returnSize[0] = rowIndex + 1;
    for (int i = 1; i <= rowIndex; ++i) {
        res[i] = 1;
        for (int j = i - 1; j >= 1; --j) {
            res[j] = res[j] + res[j - 1];
        }
    }

    return res;
}
