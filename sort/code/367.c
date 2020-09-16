bool isPerfectSquare(int num){
    double x0 = num, x1 = 0;
    while (1) {
        x1 = (num / x0 + x0) / 2;
        if (fabs(x1 - x0) < 1e-7) break;
        x0 = x1;
    }
    int n = (int) x1;
    return n * n == num;
}
