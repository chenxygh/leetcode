#define INT_MIN -2147483648

// method 1: 按部就班直接求解法 T: O(N2)  S: O(1)   超时
// int maxRotateFunction(int* A, int ASize){
//     if (ASize <= 0) return 0;
//     int max = INT_MIN;
//     for (int i = 0; i < ASize; ++i) {
//         int sum = 0;
//         for (int j = 0; j < ASize; ++j) {
//             sum += j * A[(j + ASize - i) % ASize];
//         }
//         max = sum > max? sum: max;
//     }
//     return max;    
// }

// method 2: 简化求和过程 T: O(N)  S: O(1)
// int maxRotateFunction(int* A, int ASize){
//     if (ASize <= 0) return 0;
//     int max = INT_MIN;
//     long long value = 0, sum = 0;
//     for (int i = 0; i < ASize; ++i) {
//         sum += A[i];
//         value += i * A[i];
//     }
//     max = value > max? value: max;
//     for (int i = 1; i < ASize; ++i) {
//         value += A[i - 1] * (ASize - 1) - (sum - A[i - 1]);
//         max = value > max? value: max;
//     }
//     return max;    
// }

// method 3: 同 2， 错位相消
int maxRotateFunction(int* A, int ASize){
    if (ASize <= 0) return 0;
    int max = INT_MIN;
    long value = 0, sum = 0;
    for (int i = 0; i < ASize; ++i) {
        sum += A[i];
        value += i * A[i];
    }
    max = value > max? value: max;
    for (int i = ASize - 1; i >= 1; --i) {
        value += sum - (long) ASize * A[i];
        max = value > max? value: max;
    }
    return max;    
}
