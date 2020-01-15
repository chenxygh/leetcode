void reverse (char s[], int low, int high) {
    while (low < high) {
        char temp = s[low];
        s[low++] = s[high];
        s[high--] = temp;
    }
}

char * reverseWords(char * s){
    int i = 0, j = 0;
    for (; s[j] !=  '\0'; ++j) {
        if (s[j] == ' ') {
            reverse(s, i, j - 1);
            i = j + 1;
        }
    }

    reverse (s, i, j - 1);

    return s;
}
