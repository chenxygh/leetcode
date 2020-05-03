int max (int a, int b) {
    return a > b? a: b;
}
int min (int a, int b) {
    return a < b? a: b;
}
// violent  T: O(N2) S: O(1)
// int maxArea(int* height, int heightSize){
//     int res = 0;
//     for (int i = 0; i < heightSize - 1; ++i) {
//         for (int j = i + 1; j < heightSize; ++j) {
//             res = max (res, min (height[i], height[j]) * (j - i));
//         }
//     }
//     return res;
// }

// violent (erase some cases)
// int maxArea(int* height, int heightSize){
//     int res = 0, maxLeftHeight = 0;
//     for (int i = 0; i < heightSize - 1; ++i) {
//         if (height[i] > maxLeftHeight) {
//             maxLeftHeight = height[i];
//             for (int j = i + 1; j < heightSize; ++j) {
//                 res = max (res, min (height[i], height[j]) * (j - i));
//             }
//         }
//     }
//     return res;
// }

// double pointers
int maxArea(int* height, int heightSize){
    int res = 0;
    for (int left = 0, right = heightSize - 1; left < right;) {
        int minHeight = height[left], width = right - left;
        if (height[left] < height[right]) {
            minHeight = height[left++];
        } else if (height[left] > height[right]) {
            minHeight = height[right--];
        } else {
            ++left;
            --right;
        }
        res = max (res, minHeight * width);
    }
    return res;
}
