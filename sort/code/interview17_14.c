/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

// void adjustDown (int nums[], int k, int n) {
//     int temp = nums[k - 1];
//     for (int i = k * 2; i <= n; i = k * 2) {
//         if (i + 1 <= n && nums[i] < nums[i - 1]) ++i;
//         if (temp <= nums[i - 1]) break;
//         nums[k - 1] = nums[i - 1];
//         k = i;
//     }
//     nums[k - 1] = temp;
// }

// void  createHeap (int nums[], int n) {
//     for (int i = n / 2; i >= 1; --i) adjustDown (nums, i, n);
// }

// int* smallestK(int* arr, int arrSize, int k, int* returnSize){
//     returnSize[0] = k;
//     if (k == 0) {
//         return NULL;
//     }
//     int *res = (int *)malloc(sizeof(int) * k);
//     createHeap (arr, arrSize);
//     for (int i = 0; i < k - 1; ++i) {
//         res[i] = arr[0];
//         arr[0] = arr[arrSize - i - 1];
//         arr[arrSize - i - 1] = res[i];
//         adjustDown (arr, 1, arrSize - i - 1);
//     }
//     res[k - 1] = arr[0];

//     return res;
// }

int partition (int nums[], int low, int high) {
    int pivotVal = nums[low];
    while (low < high) {
        while (low < high && nums[high] >= pivotVal) --high;
        nums[low] = nums[high];
        while (low < high && nums[low] <= pivotVal) ++low;
        nums[high] = nums[low];
    }

    nums[low] = pivotVal;
    return low;
}

int* smallestK(int* arr, int arrSize, int k, int* returnSize){
    returnSize[0] = k;
    if (k == 0) {
        return NULL;
    }
    int *res = (int *)malloc(sizeof(int) * k);

    int low = 0, high = arrSize - 1;
    int pivot = partition (arr, low, high);
    while (k - 1 != pivot) {
        if (pivot < k - 1) {
            low = pivot + 1;
        } else {
            high = pivot - 1;
        }
        pivot = partition (arr, low, high);
    }

    returnSize[0] = k;
    return arr;
}
