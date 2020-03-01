// int search(int* nums, int numsSize, int target){
//     int left = 0, right = numsSize - 1;
//     while (left <= right) {
//         int mid = left + (right - left) / 2;
//         if (nums[mid] >= target) right = mid - 1;
//         else left = mid + 1;
//     }
//     int cnt = 0;
//     for (; left < numsSize && nums[left] == target; ++left, ++cnt);
//     return cnt;
// }

int search(int* nums, int numsSize, int target){
    int left = 0, right = numsSize - 1, cnt = 0;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] > target) right = mid - 1;
        else if (nums[mid] < target) left = mid + 1;
        else {
            for (int n = mid; n >= 0 && nums[n] == target; ++cnt, --n);
            for (int n = mid + 1; n < numsSize && nums[n] == target; ++cnt, ++n);
            return cnt;
        }
    }
    return 0;
}
