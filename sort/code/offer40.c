/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int partition (int *a, int left, int right) {
    int pivot = a[left];
    while (left < right) {
        while (left < right && a[right] >= pivot) --right;
        a[left] =  a[right];
        while (left < right && a[left] <= pivot) ++left;
        a[right] = a[left];
    }
    a[left] = pivot;
    return left;
}

int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize){
    returnSize[0] = k;
    if (k == 0) return NULL;
    int left = 0, right = arrSize - 1, pivotPos = partition (arr, left, right);
    while (k != (pivotPos + 1)) {
        if (pivotPos + 1 < k) {
            left = pivotPos + 1;
        } else {
            right = pivotPos - 1;
        }
        pivotPos = partition (arr, left, right);
    }
    return arr;
}
