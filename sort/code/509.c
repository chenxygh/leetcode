int fib(int N){
    if (N == 0 || N == 1) return N;
    int f0 = 0, f1 = 1, f2 = f0 + f1;
    for (int i = 2; i <= N; ++i) {
        f2 = f0 + f1;
        f0 = f1;
        f1 = f2;
    }

    return f2;
}
