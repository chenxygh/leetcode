#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

typedef struct {
    int i;
    int j;
} QueueNode;

int getNeighbor (QueueNode v, QueueNode *w, int R, int C, int offset) {
    switch (offset) {
        case 0:
            if (v.j + 1 < C) {
                w->j = v.j + 1;
                return 1;
            }
            break;
        case 1:
            if (v.i + 1 < R) {
                w->i = v.i + 1;
                return 1;
            }
            break;
        case 2:
            if (v.j - 1 >= 0) {
                w->j = v.j - 1;
                return 1;
            }
            break;
        case 3:
            if (v.i - 1 >= 0) {
                w->i = v.i - 1;
                return 1;
            }
            break;
        default:
            break;
    }

    return 0;
}

// BFS
int** allCellsDistOrder(int R, int C, int r0, int c0, int* returnSize, int** returnColumnSizes){
    returnSize[0] = R * C;
    int **res = (int **)malloc(sizeof(int *) * R);
    for (int i = 0; i < R; ++i) {
        res[i] = (int *)malloc(sizeof(int) * 2);
        res[i][0] = 0;
        res[i][1] = 0;
    }
    int *columnSizes = (int *)malloc(returnSize[0] * sizeof(int));
    for (int i = 0; i < returnSize[0]; ++i) columnSizes[i] = 2;
    
    QueueNode Q[returnSize[0] + 1];// 无须 + 1 , 但是心安，无妨
    int length = 0;
    // int d[returnSize + 1] = {0};

    int front = 0;
    int rear = 0;
    // d[r0 * c0 + c0 + 1] = 0;
    int visited[returnSize[0] + 1];
    for (int i = 0; i < returnSize[0]; ++i) visited[i] = 0;
    visited[r0 * c0 + c0 + 1] = 1;

    res[length][0] = r0;
    res[length++][1] = c0;
    Q[rear].i = r0;
    Q[rear++].j = c0;

    while (front != rear) {
        QueueNode v = Q[front++];
        QueueNode w;
        for (int offset = 0; offset <= 3; ++offset) {
            int tag = getNeighbor(v, &w, R, C, ++offset);
            if (tag && !visited[w.i * w.j + w.j + 1]) {
                visited[w.i * w.j + w.j + 1] = 1;
                // d[w.i * w.j + w.j + 1] = d[v.i * v.j + v.j + 1] + 1;
                res[length][0] = w.i;
                res[length++][1] = w.j;
                Q[rear].i = w.i;
                Q[rear++].j = w.j;
            }
        }
    }

    return res;
}

int main(int argc, char const *argv[])
{
	int returnSize = 0;
	int *returnColumnSizes = NULL;
	printf("%d\n", returnSize);
	allCellsDistOrder(2, 2, 0, 1, &returnSize, &returnColumnSizes);
	// allCellsDistOrder(int R, int C, int r0, int c0, int* returnSize, int** returnColumnSizes)

	return 0;
}
