bool canBeEqual(int* target, int targetSize, int* arr, int arrSize){
    int hash[1001] = {0};
    for (int i = 0; i < targetSize; ++i) hash[target[i]]++;
    for (int i = 0; i < targetSize; ++i) if (--hash[arr[i]] < 0) return false;
    return true;
}
