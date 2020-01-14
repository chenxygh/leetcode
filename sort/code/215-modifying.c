#include <stdio.h>

int partition(int *nums, int low, int high) {
	int pivot = nums[low];
	while (low < high) {
		while (low < high && nums[high] <= pivot) --high;
		nums[low] = nums[high];
		while (low < high && nums[low] > pivot) ++low;
		nums[high] = nums[low];
	}
	nums[low] = pivot;

	return low;
}

// int findKthLargest(int* nums, int numsSize, int k){
//     int low = 0;
//     int high = numsSize - 1;
//     int pivotPos = partition(nums, low, high);

//     while ((pivotPos + 1) != k) {
//         if ((pivotPos + 1) < k) low = pivotPos + 1;
//         else if ((pivotPos + 1) > k) high = pivotPos - 1;
//         pivotPos = partition(nums, low, high);
//     }

//     return nums[pivotPos];
// }


void adjustUp (int nums[], int k, int low) {
    int temp = nums[low + k - 1];
    for (int i = k / 2; i >= 1; i = k / 2) {
        if (temp >= nums[low + i - 1]) break;
        nums[low + k - 1] = nums[low + i - 1];
        k = i;
    }
    nums[low + k - 1] = temp;
}

void insertHeap (int heap[], int x, int *n, int low) {
    heap[(*n)++] = x;
    adjustUp (heap, *n - low, low);
}

int findKthLargest(int* nums, int numsSize, int k){
    int n = 0;
    int low = 0;
    int heap[numsSize];
    for (int i = 0; i < numsSize; ++i) {
        insertHeap (heap, nums[i], &n, low);
        if (n >= (k + 1)) {
            ++low;
        }
    }

    return (low + 1) < numsSize && heap[low] > heap[low + 1] ? heap[low + 1]: heap[low];
}

int main(int argc, char const *argv[])
{
	int nums[] = {3, 1, 2, 4};

	printf("%d\n", findKthLargest (nums, 4, 2));

	return 0;
}
