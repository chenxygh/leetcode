/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortedSquares(int* A, int ASize, int* returnSize){
    returnSize[0] = ASize;
    int index = 0, length = 0;
    while (index < ASize && A[index] < 0) ++index;
    int *res = (int *) malloc (sizeof (int) * returnSize[0]);
    int i = index - 1, j = index;
    while (i >= 0 && j <= ASize - 1) {
        if (-A[i] < A[j]) {
            res[length++] = A[i] * A[i];
            --i;
        } else {
            res[length++] = A[j] * A[j];
            ++j;
        }
    }
    while (i >= 0) {
        res[length++] = A[i] * A[i];
        --i;
    }
    while (j <= ASize - 1) {
        res[length++] = A[j] * A[j];
        ++j;
    }
    return res;
}
