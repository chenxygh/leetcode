void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int i = m - 1, j = n - 1, length = n + m;
    while (i >= 0 && j >= 0) {
        nums1[--length] = nums1[i] > nums2[j]? nums1[i--]: nums2[j--];
    }
    while (j >= 0) {
        nums1[--length] = nums2[j--];
    }
}
