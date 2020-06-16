/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* masterMind(char* solution, char* guess, int* returnSize){
    returnSize[0] = 2;
    int dict[26] = {0}, *res = (int *)malloc (sizeof (int) * 2);
    res[0] = res[1] = 0;
    for (int i = 0; solution[i] != '\0'; ++i) {
        dict[solution[i] -'A']++;
        if (guess[i] == solution[i]) res[0]++;
    }
    for (int i = 0; solution[i] != '\0'; ++i) {
        if (dict[guess[i] - 'A']) {
            dict[guess[i] - 'A']--;
            res[1]++;
        }
    }
    res[1] -= res[0];
    return res;
}
