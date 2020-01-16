/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParity(int* A, int ASize, int* returnSize){
    int low = 0;
    int high = ASize - 1;
    int pivot = A[low];

    while (low < high) {
        while (low < high && A[high] % 2) --high;
        A[low] = A[high];
        while (low < high && A[low] % 2 == 0) ++low;
        A[high] = A[low];
    }
    A[low] = pivot;

    returnSize[0] = ASize;
    return A;
}
