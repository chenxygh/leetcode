bool canWinNim(int n){
    if (n <= 3) return true;
    return n % 4;
}
