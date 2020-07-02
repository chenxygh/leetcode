int getVal (char c) {
    switch (c) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
    }
    return 0;
}

int romanToInt(char * s) {
    if (s == NULL) return 0;
    int res = 0;
    for (int i = 0, pre = 0, val = 0; s[i] != '\0'; ++i) {
        val = getVal (s[i]);
        res = pre < val? res - pre + (val - pre): res + val;
        pre = val;
    }
    return res;
}
