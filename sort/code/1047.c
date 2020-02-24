char * removeDuplicates(char * S){
    char *stack = (char *)malloc(sizeof(char) * (20000 + 2));
    int top = -1;

    for (int i = 0; S[i] != '\0'; ++i) {
        if (top == -1 || stack[top] != S[i]) {// 短路计算，无妨
            stack[++top] = S[i];
            continue;
        }
        top--;
    }

    stack[top + 1] = '\0';
    return stack;
}

char * removeDuplicates(char * S){
    int i = 0, j = 1;
    for (;S[i] != '\0' && S[j] != '\0'; ++j) {
        if (S[i] == S[j]) {
            if (--i < 0) S[++i] = S[++j];
        } else S[++i] = S[j];
    }

    S[i] != '\0'? S[i + 1] = '\0': 0;
    return S;
}
