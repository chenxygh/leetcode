int partition(int *nums, int low, int high) {
    int pivot = nums[low];
    while (low < high) {
        while (low < high && nums[high] <= pivot) --high;
        nums[low] = nums[high];
        while (low < high && nums[low] >= pivot) ++low;
        nums[high] = nums[low];
    }
    nums[low] = pivot;

    return low;
}

int findKthLargest(int* nums, int numsSize, int k){
    int low = 0;
    int high = numsSize - 1;
    int pivotPos = partition(nums, low, high);

    while ((pivotPos + 1) != k) {
        if ((pivotPos + 1) < k) low = pivotPos + 1;
        else if ((pivotPos + 1) > k) high = pivotPos - 1;
        pivotPos = partition(nums, low, high);
    }

    return nums[pivotPos];
}
