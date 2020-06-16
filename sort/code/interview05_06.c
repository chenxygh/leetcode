int convertInteger(int A, int B){
    unsigned int n = A ^ B ,res = 0;
    while (n) {
        ++res;
        n &= n - 1;
    }
    return res;
}
