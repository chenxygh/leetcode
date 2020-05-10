// int lastRemaining(int n, int m){
//     int res = 0;
//     for (int i = 2; i <= n; ++i) {
//         res = (res + m) % i;
//     }
//     return res;
// }

int lastRemaining(int n, int m){
    return n == 1? 0: (lastRemaining (n - 1, m) + m) % n;
}
