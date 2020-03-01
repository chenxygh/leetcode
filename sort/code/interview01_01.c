// bool isUnique(char* astr){
//     int dict[26] = {0};
//     for (int i = 0; astr[i] != '\0'; ++i) {
//         if (++dict[astr[i] - 'a'] > 1) return false;
//     }
//     return true;
// }

bool isUnique(char* astr){
    int res = 0;
    for (int i = 0; astr[i] != '\0'; ++i) {
        int move = astr[i] - 'a';
        if (res & (1 << move)) return false;
        res |= (1 << move);
    }
    return true;
}
