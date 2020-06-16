void reverse (char *s, int n) {
    for (int i = 0, j = n - 1; i < j; ++i, --j) {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

char* reverseLeftWords(char* s, int n){
    int length = strlen (s);
    reverse (s, n);
    reverse (s + n, length - n);
    reverse (s, length);
    return s;
}
