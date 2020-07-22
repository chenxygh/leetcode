// method 1: recursion -- simple
// int findMin(int* nums, int numsSize){
//     if (numsSize == 1) return nums[0];
//     if (numsSize == 2) return nums[0] < nums[1]? nums[0]: nums[1];

//     int mid = (numsSize - 1) / 2;
//     return nums[numsSize - 1] < nums[mid]? findMin (nums + mid, numsSize - mid): findMin (nums, mid + 1);
// }

// method 2: recursion -- optimized
// int findMin(int* nums, int numsSize){
//     if (numsSize == 1) return nums[0];
//     int mid = (numsSize - 1) / 2;
//     return nums[numsSize - 1] < nums[mid]? findMin (nums + mid + 1, numsSize - mid - 1): findMin (nums, mid + 1);
// }

// method 3: iteration -- optimized
int findMin(int* nums, int numsSize){
    int left = 0, right = numsSize - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < nums[right]) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return nums[left];
}
