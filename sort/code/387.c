int firstUniqChar(char * s){
    int dict[26] = {0};
    for (int i = 0; s[i] != '\0'; ++i) dict[s[i] - 'a']++;
    for (int i = 0; s[i] != '\0'; ++i) if (dict[s[i] - 'a'] == 1) return i;
    return -1;
}
