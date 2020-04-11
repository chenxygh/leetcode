// method 1: dynamic programming  T: O(N) S: O(1)
// int maxProfit(int* prices, int pricesSize){
//     if (pricesSize == 0) return 0;
//     int maxProfit = 0, minPrice = prices[0];
//     for (int i = 0; i< pricesSize; ++i) {
//         if (prices[i] < minPrice) minPrice = prices[i];
//         else if (prices[i] - minPrice > maxProfit) {
//             maxProfit = prices[i] - minPrice;
//         }
//     }

//     return maxProfit;
// }

// method 2: violence algorithm  T: O(N2) S: O(N)
// int maxProfit(int* prices, int pricesSize){
//     if (pricesSize == 0) return 0;
//     int maxProfit = 0;
//     for (int i = 0; i < pricesSize - 1; ++i) {
//         for (int j = i + 1; j < pricesSize; ++j) {
//             maxProfit = prices[j] - prices[i] > maxProfit? prices[j] - prices[i]: maxProfit;
//         }
//     }

//     return maxProfit;
// }

// method 3: monotonic stack  T: O(N) S: O(N)
int maxProfit(int* prices, int pricesSize){
    int stack[100000];
    int top = -1, maxProfit = 0;
    for (int i = 0; i < pricesSize; ++i) {
        while (top != -1 && prices[i] < stack[top]) {
            maxProfit = stack[top] - stack[0] > maxProfit? stack[top] - stack[0]: maxProfit;
            --top;
        }
        stack[++top] = prices[i];
    }
    while (top != -1) {
        maxProfit = stack[top] - stack[0] > maxProfit? stack[top] - stack[0]: maxProfit;
        --top;
    }

    return maxProfit;
}
