int min (int a, int b) {
    return a < b? a: b;
}

// n[i] = min (n[i - 1] + cost[i - 1], n[i - 2] + cost[i - 2])
// int minCostClimbingStairs(int* cost, int costSize){
//     int n[3] = {0};

//     for (int i = 2; i <= costSize; ++i) {
//         n[2] = min (cost[i - 1] + n[1], cost[i - 2] + n[0]);
//         n[0] = n[1];
//         n[1] = n[2];

//     }
//     return n[2];
// }

// n[i] = min (n[i - 1], n[i - 2]) + cost[i]
// res = min (n[costSize - 1], n[costSize - 2])
int minCostClimbingStairs (int *cost, int costSize) {
    int n[3];
    n[0] = cost[0];
    n[1] = cost[1];
    for (int i = 2; i < costSize; ++i) {
        cost[i] = min (cost[i - 1], cost[i - 2]) + cost[i];
    }
    return min (cost[costSize - 1], cost[costSize - 2]);
}
