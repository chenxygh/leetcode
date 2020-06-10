bool isValid (char *c) {
    return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

bool isPalindrome(char * s){
    if (s == NULL || s[0] == '\0') return true;
    int length = 0;
    for (int i = 0; s[i] != '\0'; ++i) {
        if (isValid (s[i])) s[length++] = tolower (s[i]);
    }
    int left = 0, right = length - 1;
    while (left < right && s[left] == s[right]) {
        ++left;
        --right;
    }
    return left >= right;
}
