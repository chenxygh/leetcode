int countSegments(char * s){
    int cnt = 0;
    for (int i = 0; s[i] != '\0';) {
        while (s[i] != '\0' && s[i] == ' ') ++i;
        if (s[i] == '\0') return cnt;
        ++cnt;
        while (s[i] != '\0' && s[i] != ' ') ++i;
    }
    return cnt;
}
