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