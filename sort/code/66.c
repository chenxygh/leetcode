/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
    int *res = (int *)malloc(sizeof(int) * (digitsSize + 1));
    int cin = 0, sum = 0;
    sum = digits[digitsSize - 1] + 1 + cin;
    res[digitsSize] = sum % 10;
    cin = sum / 10;

    for (int i = 1; i < digitsSize; ++i) {
        sum = digits[digitsSize - i - 1] + cin;
        res[digitsSize - i] = sum % 10;
        cin = sum / 10;
    }
    res[0] = 1;
    returnSize[0] = cin? digitsSize + 1: digitsSize;
    return cin? res: res + 1;
}
