#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void adjustDown (int a[], int k, int n) {
	int temp = a[k - 1];
	for (int i = k * 2; i <= n; i = k * 2) {
		if ( i + 1 <= n && a[i + 1 - 1] > a[i - 1]) ++i;
		if (temp >= a[i - 1]) break;
		a[k - 1] = a[i - 1];
		k = i;
	}
	a[k - 1] = temp;
}

void buildHeap (int a[], int n) {
	for (int i = n / 2; i >= 1; --i)
		adjustDown(a, i, n);
}

void heapSort (int a[], int n) {
	buildHeap(a, n);
	for (int i = n - 1; i > 0; --i) {
		int temp = a[i];
		a[i] = a[0];
		a[0] = temp;
		adjustDown(a, 1, i);
	}
}

// method 1: sort
// int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
// 	int *res = (int *)malloc(1 * sizeof(int));
// 	int length = 0;

// 	heapSort(nums1, nums1Size);
// 	heapSort(nums2, nums2Size);
// 	for (int i = 0, j = 0; i < nums1Size && j < nums2Size; ) {
// 		if (nums1[i] < nums2[j]) {
// 			++i;
// 		} else if (nums1[i] > nums2[j]) {
// 			++j;
// 		} else {
// 			res = (int *)realloc(res, ++length * sizeof(int));
// 			res[length - 1] = nums1[i];
// 			++i;
// 			++j;
// 		}
// 	}

// 	returnSize[0] = length;
// 	return res;
// }

// method 2: hash
// 哈希表元素，保存数据值和该数据出现次数，二者不可或缺
// 数组长度较小者，选为哈希表长

typedef struct hashNode {
    int elem;
    int info;
} hashNode;

int isPrimeNumber (int num) {
	if (num== 1) return 0;
	if (num== 2) return 1;
	if (num% 2 == 9) return 0;

	int n = sqrt(num);
	for (int i = 3; i <= n; i += 2) {
		if (num % i == 0) return 0;
	}
	return 1;
}

int getPrimeNumber (int m) {
    if (m == 1) return 1;

    for (int i = m; i >= 2; --i) {
    	if (isPrimeNumber(i)) return i;
    }
    return 0;
}

int hashToAddr (int key, int p, int m, int i) {
	return (key % p + i) % m;
}

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
	if (nums1Size == 0 || nums2Size == 0) {
		returnSize[0] = 0;
		return NULL;
	}

    int *nums = NULL;
    int n = 0;
    if (nums1Size < nums2Size) {
        n = nums1Size;
        nums = nums1;
    } else {
        n = nums2Size;
        nums = nums2;
    }

    int m = 10 * n / 7;// 散列因子 约  0.7

    hashNode hash[m];
    for (int i = 0; i < m; ++i) hash[i].info = -1;

    int p = getPrimeNumber(m);// 最靠近 m 的素数

    for (int i = 0; i < n; ++i) {
    	int cnt = 0;
        int addr = hashToAddr(nums[i], p, m, cnt);
        while (hash[addr].info != -1 && hash[addr].elem != nums[i]) addr = hashToAddr(nums[i], p, m, ++cnt);
        if (hash[addr].info == -1) {
        	hash[addr].elem = nums[i];
        	hash[addr].info = 0;
        }
        hash[addr].info++;
    }
    for (int i = 0; i < m; ++i) printf("elem: %d info: %d\n", hash[i].elem, hash[i].info);

    if (nums == nums1) {
        n = nums2Size;
        nums = nums2;
    } else {
        n = nums1Size;
        nums = nums1;
    }

    int *res = (int *)malloc(1 * sizeof(int));
    int length = 0;
    for (int i = 0; i < n; ++i) {
    	int cnt = 0;
        int addr = hashToAddr(nums[i], p, m, cnt);
        int initAddr = addr;

        if (hash[addr].info == -1) continue;// 初始为空, 无元素, 不是交集，跳过

        if (hash[addr].elem != nums[i]) {// 初始不为空，有元素存在
        	addr = hashToAddr(nums[i], p, m, ++cnt);
        	while (hash[addr].info != -1 && hash[addr].elem != nums[i] && addr != initAddr) addr = hashToAddr(nums[i], p, m, ++cnt);
        	if (hash[addr].info == -1 || addr == initAddr) continue;// 不是交集，跳过
        }

        if (hash[addr].info == 0) continue;

        res = (int *)realloc(res, ++length * sizeof(int));
        res[length - 1] = hash[addr].elem;
        hash[addr].info--;
    }

    returnSize[0] = length;
    return res;
}

int main(int argc, char const *argv[])
{
	int nums1[] = {9,1};
	int nums2[] = {7,8,3,9,0,0,9,1,5};
	int returnSize = 0;
	int *res = intersect (nums1, 2, nums2, 9, &returnSize);
	for (int i = 0; i < returnSize; ++i) printf(" %d", res[i]);

	return 0;
}
