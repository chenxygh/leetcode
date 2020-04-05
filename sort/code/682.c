int calPoints(char ** ops, int opsSize){
    int nums_stack[1000] ={0};
    int points_stack[1000] = {0};
    int top = 0;
    for (int i = 0; i < opsSize; ++i) {
        if (ops[i][0] <= '9' && ops[i][0] >= '0' || ops[i][0] == '-') {
            int sign = ops[i][0] == '-'? -1: 1;
            int num = 0;
            for (int j = sign == 1? 0: 1; ops[i][j] != '\0'; ++j) {
                num = num * 10 + ops[i][j] - '0';
            }
            nums_stack[++top] = num * sign;
            points_stack[top] = points_stack[top - 1] + nums_stack[top];
        } else if (ops[i][0] == 'C') {
            --top;
        } else if (ops[i][0] == 'D') {
            nums_stack[++top] = nums_stack[top] * 2;
            points_stack[top] = points_stack[top - 1] + nums_stack[top];
        } else if (ops[i][0] == '+') {
            nums_stack[++top] = nums_stack[top] + nums_stack[top - 1];
            points_stack[top] = points_stack[top - 1] + nums_stack[top];
        }
    }

    return points_stack[top];
}
