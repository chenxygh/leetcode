#include <stdio.h>

void adjustDown (int a[], int k, int n) {
    int temp = a[k - 1];
    for (int i = 2 * k; i <= n; i = 2 * k) {
        if (i + 1 <= n && a[i + 1 - 1] > a[i -1]) ++i;
        if(temp >= a[i - 1]) break;
        a[k - 1] = a[i - 1];
        k = i;
    }
    a[k - 1] = temp;
}

void buildHeap (int a[], int n) {
    for (int i = n / 2; i >= 1; --i) {
        adjustDown(a, i, n);
    }
}

void heapSort (int a[], int n) {
	buildHeap(a, n);
    for (int i = n - 1; i >= 1; --i) {
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        adjustDown(a, 1, i);
    }
}

// 三角形成立且面积 > 0 <<--->> S = sqrt(p(p - a)(p - b)(p - c)) 存在 且 > 0, p = (a + b + c) / 2
int largestPerimeter(int* A, int ASize){
    heapSort(A, ASize);

    int i = ASize - 1;

    while ( i - 2 >= 0 && A[i - 1] + A[i - 2] <= A[i]) --i;

    return k - 2 < 0? 0: A[i - 2] + A[i - 1] + A[i];
}

int main(int argc, char const *argv[])
{
	int a[] = {1, 2, 1};
	heapSort(a, 3);

	for (int i = 0; i < 3; ++i) printf("%d\n", a[i]);

	return 0;
}
