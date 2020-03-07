int hammingDistance(int x, int y){
    int cnt = 0;
    unsigned int num = x ^ y;

    while (num) {
        ++cnt;
        num &= num - 1;
    }

    return cnt;
}
