bool isValid(char * s){
    int length = strlen(s);
    if (length == 0) return true;
    char stack[length];
    int top = -1;
    for (int i = 0; i < length; ++i) {
        if (top == -1) {
            stack[++top] = s[i];
            continue;
        }

        if (s[i] == '(' || s[i] == '[' || s[i] == '{') stack[++top] = s[i];
        else if ((s[i] == ')' && stack[top] == '(') || (s[i] == ']' && stack[top] == '[') || (s[i] == '}' && stack[top] == '{')) {
            --top;
        } else {
            return false;
        }
    }

    return top == -1;
}
