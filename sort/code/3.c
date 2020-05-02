int max (int a, int b) {
    return a > b? a: b;
}

int lengthOfLongestSubstring(char * s){
    int dict[128] = {0}, res = 0;
    for (int i = 0, j = 0; s[i] != '\0'; ++i) {
        for (; s[j] != '\0' && dict[s[j]] == 0; dict[s[j]] = 1, ++j);
        res = max (res, j - i);
        if (s[j] == '\0') return res;
        dict[s[i]] = 0;
    }
    return res;
}
