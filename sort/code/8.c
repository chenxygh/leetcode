#define INT_MAX 2147483647
#define INT_MIN -2147483648

bool isDigit (char s) {
    return s <= '9' && s >= '0';
}

int myAtoi(char * str){
    while (str[0] == ' ') ++str;
    if (str[0] != '+' && str[0] != '-' && !isDigit(str[0])) return 0;
    int sign = str[0] == '+'? 1: str[0] == '-'? -1: 1;
    if (!isDigit(str[0])) ++str;

    int res = 0;
    while (str[0] == '0') ++str;
    while (isDigit (str[0])) {
        int digit = str[0] - '0';
        if (sign == 1 && (res > INT_MAX / 10 || (res == INT_MAX / 10 && digit > 7))) return INT_MAX;
        if (sign == -1 && (res < INT_MIN / 10 || (res == INT_MIN / 10 && digit > 8))) return INT_MIN;
        res = res * 10 + (digit * sign);
        ++str;
    }

    return res;
}
