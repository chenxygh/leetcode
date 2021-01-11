int max (int a, int b) {
    return a > b? a: b;
}
int largestRectangleArea(int* heights, int heightsSize){
    int stack[heightsSize], top = -1, res = 0;
    for (int i = 0; i < heightsSize; ++i) {
        while (top != -1 && heights[stack[top]] > heights[i]) {
            res = max (res, heights[stack[top]] * (--top == -1? i: i - stack[top] - 1));
        }
        stack[++top] = i;
    }
    while (top != -1) {
        res = max (res, heights[stack[top]] * (--top == -1? heightsSize: heightsSize - stack[top] - 1));
    }
    return res;
}

int maximalRectangle(char** matrix, int matrixSize, int* matrixColSize){
    if (matrixSize == 0 || matrix == NULL || matrix[0] == NULL || matrixColSize == NULL || matrixColSize[0] == 0) return 0;
    int heightsSize = matrixColSize[0], heights[heightsSize], res = 0;
    for (int i = 0; i < heightsSize; ++i) heights[i] = matrix[0][i] - '0';
    for (int i = 1; i < matrixSize; ++i) {
        for (int j = 0; j < heightsSize; ++j) {
            heights[j] = matrix[i][j] == '0'? 0: heights[j] + 1;
        }
        res = max (res, largestRectangleArea (heights, heightsSize));
    }
    return res;
}
