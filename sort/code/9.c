bool isPalindrome(int x) {
    if (x < 0 || (x > 0 && x % 10 == 0)) return false;
    int val = 0;
    while (val < x) {
        val = val * 10 + x % 10;
        x /= 10;
    }
    return val == x || val / 10 == x;
}
