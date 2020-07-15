int add(int a, int b){
    unsigned int x = a, y = b, carry = (x & y) << 1, res = x ^ y;
    while (carry) {
        x = carry;
        y = res;
        res = x ^ y;
        carry = (x & y) << 1;
    }
    return res;
}
