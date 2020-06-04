#include <stdio.h>
#include <stdlib.h>

int toStr (int nums, char *str, int length) {
    if (nums == 0) return 0;
    length = toStr (nums / 10, str, length);
    str[length++] = nums % 10 + '0';
    return length;
}

char * getHint(char * secret, char * guess){
    int a = 0, b = 0, dict[10] = {0};
    for (int i = 0; secret[i] != '\0'; ++i) {
        if (secret[i] == guess[i]) ++a;
        ++dict[secret[i] - '0'];
    }
    for (int i = 0; secret[i] != '\0'; ++i) {
        if (dict[guess[i] - '0']) {
            --dict[guess[i] - '0'];
            ++b;
        }
    }
    char *res = (char *)malloc (sizeof(char) * 20);
    sprintf (res, "%dA%dB", a, b - a);
    return res;
}

int main(int argc, char const *argv[]) {
	char secret[] = "1", guess[] = "0";
	printf("%s\n", getHint (secret, guess));
	return 0;
}
