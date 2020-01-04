/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParityII(int* A, int ASize, int* returnSize){
    int *res = (int *)malloc(ASize * sizeof(int));
    returnSize[0] = ASize;

    for (int i = 0, j = 1; i < ASize && j < ASize; i += 2) {
        if (A[i] % 2) {// 偶数位上的奇数
            while (j < ASize && A[j] % 2) j += 2;// 找到奇数序列的最近异常点(奇数位上的偶数)
            if (j < ASize) {// 异常点处理，使奇数序列有序
                int temp = A[i];
                A[i] = A[j];
                A[j] = temp;
                j += 2;
            }
        }
    }

    // 拷贝，题意要求新数组，那就简单拷贝，懒得优化
    for (int i = 0; i < ASize; ++i) res[i] = A[i];

    return res;
}
