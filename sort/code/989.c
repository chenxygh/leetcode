/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// int* addToArrayForm(int* A, int ASize, int K, int* returnSize){
//     int length = (ASize + 1) > 5? (ASize + 1): 5;
//     int n = length;
//     int *res = (int *)malloc(sizeof(int) * n);
	
//     int count = 0;
//     for (int i = ASize - 1; i >= 0 || K; --i) {
//         int sum = (K? K % 10 : 0)  + (i >= 0? A[i]: 0) + count;
//         K = K? K / 10: 0;
//         count = sum / 10;
//         res[--n] = sum % 10;
//     }
//     if (count) res[--n] = 1;
//     returnSize[0] = length - n;
//     return res + n;
// }

int* addToArrayForm(int* A, int ASize, int K, int* returnSize){
	int length = (ASize + 1) > 5? (ASize + 1): 5;
	int n = length;
	int *res = (int *)malloc(sizeof(int) * n);
	
	int count = 0;
	for (int i = ASize - 1; i >= 0 || K; --i) {
		K = K + (i >= 0? A[i]: 0);
		res[--n] = K % 10;
		K /= 10;
	}
	if (count) res[--n] = 1;
	returnSize[0] = length - n;
	return res + n;
}
