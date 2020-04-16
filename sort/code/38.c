char * countAndSay(int n){
    char *vec = (char *)malloc(sizeof(char) * 10000);
    char *res = vec + 5000;
    vec[0] = res[0] = '1';
    vec[1] = res[1] = '\0';

    for (int i = 1; i < n; ++i) {
        int length = 0;
        char *temp = res;
        res = vec;
        vec = temp;
        for (int j = 0; vec[j] != '\0';) {
            int cnt = 1;
            while (vec[++j] != '\0' && vec[j - 1] == vec[j]) ++cnt;
            res[length++] = cnt + '0';
            res[length++] = vec[j - 1];
        }
        res[length] = '\0';
    }
    return res;
}
