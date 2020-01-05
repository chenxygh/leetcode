#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

// method 1: O(N2)
// int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
//     returnSize[0] = nums1Size;

//     int *res = (int *)malloc(returnSize[0] * sizeof(int));
//     int n = 0;

//     for (int i = 0; i < nums1Size; ++i) {
//         int j = 0;
//         while (nums2[j] != nums1[i]) ++j;
//         for (; j < nums2Size && nums2[j] <= nums1[i]; ++j);
//         res[n++] = j < nums2Size? nums2[j]: -1;
//     }

//     return res;
// }

// method 2: hash & stack
typedef struct hashNode {
    int elem;
    int info;
} hashNode;

int isPrimeNumber (int num) {
    if (num == 1) return 0;
    if (num == 2) return 1;
    if (num % 2 == 0) return 0;

    int n = sqrt(num);
    for (int i = 3; i <= n; i += 2) {
        if (num % i == 0) return 0;
    }
    
    return 1;
}

int getPrimeNumber (int m) {
    if (m == 1) return 1;
    for (int i = m; i >= 2; --i) {
        if (isPrimeNumber (i)) return i;
    }
    return 0;
}

int hashToAddr (int key, int p, int m, int i) {
    return (key % p + i) % m;
}

void insertHash (hashNode hash[], int key, int info, int p, int m) {
    int cnt = 0;
    int addr = hashToAddr(key, p, m, cnt);
    int initAddr = addr;
    if (hash[addr].elem != 0) {
    	addr = hashToAddr(key, p, m, ++cnt);
    	while (hash[addr].elem != 0 && addr != initAddr) addr = hashToAddr(key, p, m, ++cnt);
    }
    if (hash[addr].elem == 0) {
    	hash[addr].elem = key;
    	hash[addr].info = info;
    }
}

int findHash (hashNode hash[], int key, int p, int m) {
    int cnt = 0;
    int addr = hashToAddr(key, p, m, cnt);
    int initAddr = addr;
    if (hash[addr].elem != key) {
    	addr = hashToAddr(key, p, m, ++cnt);
    	while (hash[addr].elem != key && addr != initAddr) addr = hashToAddr(key, p, m, ++cnt);
    }

    return hash[addr].elem == key? hash[addr].info: -1;
}

int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    returnSize[0] = nums1Size;
    int *res = (int *)malloc(returnSize[0] * sizeof(int));
    
    int n = nums2Size;
    int m = 10 * n / 7;
    int p = getPrimeNumber(m);
    hashNode hash[m > 0? m: 1];
    for (int i = 0; i < nums2Size; ++i) hash[i].elem = hash[i].info = 0;

    int stack[(nums2Size > 0? nums2Size: 1) + 1];
    int top = -1;

    // build hashMap
    for(int i = 0; i < nums2Size;) {
        if (top == -1) {
            stack[++top] = nums2[i];
            continue;
        }
        if (stack[top] < nums2[i]) {
            insertHash (hash, stack[top--], nums2[i], p, m);
        } else {
            stack[++top] = nums2[i];
            ++i;
        }
    }
    while (top >= 0) insertHash (hash, stack[top--], -1, p, m);

    // build res array
    for (int i = 0; i < nums1Size; ++i) {
        res[i] = findHash (hash, nums1[i], p, m);
    }

    return res;
}

int main(int argc, char const *argv[])
{
	int nums1[] = {3,1,5,7,9,2,6};
	int nums2[] = {1,2,3,5,6,7,9,11};
	int returnSize = 0;
	int *res = nextGreaterElement (nums1, 7, nums2, 8, &returnSize);
	for (int i = 0; i < returnSize; ++i) printf(" %d", res[i]);

	return 0;
}
