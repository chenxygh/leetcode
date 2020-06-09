double myPow(double x, int n){
    int sign = n < 0? -1: 1;
    unsigned int exp = fabs(n);
    double res = 1.0;
    while (exp) {
        if (exp & 1) res *= x;
        x *= x;
        exp >>= 1;
    }
    return sign == -1? 1.0 / res: res;
}
