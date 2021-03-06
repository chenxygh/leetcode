// method 1: and
// int bitwiseComplement(int N){
//     if (N == 0) return 1;
//     unsigned int res = ~N;
//     while (N & N - 1) {
//         N &= N - 1;
//     }
//     return res & (N - 1);
// }

// method 2: xor
// int bitwiseComplement(int N){
//     if (N == 0) return 1;
//     unsigned int res = N;
//     while (N & N - 1) {
//         N &= N - 1;
//     }
//     return res ^ ((N - 1) << 1 | 1);
// }

// method 3: substract
int bitwiseComplement(int N){
    if (N == 0) return 1;
    unsigned int res = N;
    while (N & N - 1) {
        N &= N - 1;
    }
    return ((N - 1) << 1 | 1) - res;
}
