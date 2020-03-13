#define INT_MIN -2147483648
#define INT_MAX 2147483647

bool isDigit (char s) {
    return s <= '9' && s >= '0';
}

int strToInt(char* str){
    int res = 0;
    while (str[0] == ' ') ++str;
    if (str[0] != '+' && str[0] != '-' && !isDigit (str[0])) return 0;
    int sign = str[0] == '+'? 1: str[0] == '-'? -1: 1;

    if (!isDigit (str[0])) ++str;
    while (str[0] == '0') ++str;
    while (str[0] <= '9' && str[0] >= '0') {
    	if (sign == 1 && (res > INT_MAX / 10 || (res == INT_MAX / 10 && (str[0] - '0') > 7))) return INT_MAX;
        if (sign == -1 && (res < INT_MIN / 10 || (res == INT_MIN / 10 && (str[0] - '0') > 8))) return INT_MIN;
        res *= 10;
        res += (str[0]  - '0') * sign;
        ++str;
    }

    return res;
}
