int add(int a, int b){
    unsigned int res = a ^ b, cin = a & b;
    while (cin) {
        a = res;
        b = cin << 1;
        res = a ^ b;
        cin = a & b;
    }
    return res;
}
