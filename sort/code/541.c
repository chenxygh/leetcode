void reverse (char str[], int low, int high) {
    while (low < high) {
        char temp = str[low];
        str[low++] = str[high];
        str[high--] = temp;
    }
}

char * reverseStr(char * s, int k){
    int length = strlen(s);
    for (int i = 0, j = k - 1; i < length; j +=  2 * k, i = j - k + 1) {
        reverse (s, i, j < length - 1? j: length - 1);
    }

    return s;
}
