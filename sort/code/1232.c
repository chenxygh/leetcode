bool checkStraightLine(int** coordinates, int coordinatesSize, int* coordinatesColSize){
    float denominator = coordinates[1][0] - coordinates[0][0];
    if (denominator != 0) {
        float slop = (float) (coordinates[1][1] - coordinates[0][1]) / (coordinates[1][0] - coordinates[0][0]);
        for (int i = 2; i< coordinatesSize; ++i) {
            if ((coordinates[i][0] - coordinates[i - 1][0]) == 0) return false;
            float tmpSlop = (float) (coordinates[i][1] - coordinates[i - 1][1]) / (coordinates[i][0] - coordinates[i - 1][0]);
            if (slop != tmpSlop) return false;
        }
    } else {
        for (int i = 2; i< coordinatesSize; ++i) {
            if ((coordinates[i][0] - coordinates[i - 1][0]) != 0) return false;
        }
    }
    return true;
}

// 叉乘
bool checkStraightLine(int** coordinates, int coordinatesSize, int* coordinatesColSize){
    int x0 = coordinates[1][0] - coordinates[0][0], y0 = coordinates[1][1] - coordinates[0][1];
    for (int i = 2; i < coordinatesSize; ++i) {
        int x1 = coordinates[i][0] - coordinates[0][0], y1 = coordinates[i][1] - coordinates[0][1];
        if (x0 * y1 != x1 * y0) {
            return false;
        }
    }
    return true;
}