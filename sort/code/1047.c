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
