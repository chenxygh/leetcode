bool CheckPermutation(char* s1, char* s2){
    int dict[26] = {0};
    for (int i = 0; s1[i] != '\0'; ++i) dict[s1[i] - 'a']++;
    for (int i = 0; s2[i] != '\0'; ++i) if (--dict[s2[i] - 'a'] < 0) return false;
    for (int i = 0; i < 26; ++i) if (dict[i]) return false;
    return true;
}
