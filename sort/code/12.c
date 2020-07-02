// method 1: original version
// int toNums (int num, int **nums, int length) {
//     if (num == 0) return length;
//     length = toNums (num / 10, nums, length + 1);
//     nums[0][0] = num % 10;
//     nums[0]++;
//     return length;
// }

// char * intToRoman(int num){
//     int nums[4] = {0}, *p = nums, n = 0, length = toNums (num, &p, 0);
//     char dict[][4] = {"IVX", "XLC", "CDM", "M"};
//     char *res = (char *) malloc (sizeof (char) * 17);
//     for (int i = 0; i < length; ++i) {
//         int index = length - i - 1, val = nums[i];
//         if (val == 0) continue;
//         if (val <= 3 && val >= 1) {
//             for (int j = 0; j < val; ++j) res[n++] = dict[index][0];
//         } else if (val == 4) {
//             res[n++] = dict[index][0];
//             res[n++] = dict[index][1];
//         } else if (val == 9) {
//             res[n++] = dict[index][0];
//             res[n++] = dict[index][2];
//         } else if (val == 5) {
//             res[n++] = dict[index][1];
//         } else {
//             res[n++] = dict[index][1];
//             for (int j = 5; j < val; ++j) res[n++] = dict[index][0];
//         }
//     }
//     res[n] = '\0';
//     return res;
// }

// method 2: greedy algorithm
// char * intToRoman(int num) {
//     char dict[][3] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
//     int nums[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
//     int n = 0;
//     char *res = (char *) malloc (sizeof (char) * 17);
//     for (int i = 0; i < 13 && num;) {
//         if (nums[i] > num) {
//             ++i;
//             continue;
//         }
//         for (int j = 0; dict[i][j] != '\0'; ++j) {
//             res[n++] = dict[i][j];
//         }
//         num -= nums[i];
//     }
//     res[n] = '\0';
//     return res;
// }

// method 3: greedy algorithm optimized
char * intToRoman(int num) {
    char dict[][3] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int nums[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char *res = (char *) malloc (sizeof (char) * 17);
    res[0] = '\0';
    for (int i = 0; i < 13 && num; ++i) {
        if (nums[i] > num) continue;
        int cnt = num / nums[i];
        while (cnt--) strcat (res, dict[i]);
        num %= nums[i];
    }
    return res;
}
