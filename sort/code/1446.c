int maxPower(char * s){
    int res = 1, cnt = 1;
    for (int i = 1; s[i] != '\0'; ++i) {
        if (s[i] != s[i - 1]) cnt = 1;
        else res = ++cnt > res? cnt: res;
    }
    return res;
}
