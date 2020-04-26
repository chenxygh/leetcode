int max (int a, int b) {
    return a > b? a: b;
}
int largestRectangleArea(int* heights, int heightsSize){
    if (heightsSize == 0) return 0;
    int stack[heightsSize], top = -1, res = 0;
    for (int i = 0; i < heightsSize; ++i) {
        while (top != -1 && heights[stack[top]] > heights[i]) {
            res = max (res, heights[stack[top]] * (top - 1 == -1? i: i - stack[top - 1] - 1));
            --top;
        }
        stack[++top] = i;
    }
    while (top != -1) {
        res = max (res, heights[stack[top]] * (top - 1 == -1? heightsSize: heightsSize - stack[top - 1] - 1));
        --top;
    }
    return res;
}
