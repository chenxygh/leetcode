// int strStr(char * haystack, char * needle){
//     int i = 0, j = 0, n = 0;
//     while (haystack[i] != '\0' && needle[j] != '\0') {
//         if (haystack[i] == needle[j]) {
//             ++i;
//             n = ++j;
//         } else {
//             i = i - j + 1;
//             j = 0;
//         }
//     }
//     return needle[j] == '\0'? i - n: -1;
// }

// method 2: KMP

void get_next (char *t, int *next) {
    int i = 0, j = -1;
    next[0] = -1;
    while (t[i + 1] != '\0') {
        if (j == -1 || t[i] == t[j]) {
            next[++i] = ++j;
        } else {
            j = next[j];
        }
    }
}

int strStr(char * haystack, char * needle){
    if (needle[0] == '\0') return 0;
    int i = 0, j = 0, n = strlen(needle), next[n];
    get_next (needle, next);
    while (haystack[i] != '\0' && (j == -1 || needle[j] != '\0')) {
        if (j == -1 || haystack[i] == needle[j]) {
            ++i;
            ++j;
        } else {
            j = next[j];
        }
    }
    return needle[j] == '\0'? i - n: -1;
}
